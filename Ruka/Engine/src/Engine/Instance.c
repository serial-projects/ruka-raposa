/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Instance.h"
#include "Engine/Redirects/NK.h"
#include "Engine/Enums.h"
#include "Engine/Mode/Base.h"

EN_Instance*
EN_InstanceNew()
{
    EN_Instance* new_instance =
        (EN_Instance*)(
            NK_AllocatorGet(
                sizeof(EN_Instance)
            )
        );
    return new_instance;
}

void
EN_InstanceFree(
    EN_Instance* instance
)
{
    NK_AllocatorFree(instance);
}

void
EN_InstanceConstruct(
    EN_Instance* instance
)
{
    /** We construct the modes: */
    EN_InitializationModeConstruct(
        (EN_InitializationMode*)(
            &instance->modes[EN_ENUMS_ENGINE_MODE_INITIALIZATION]
        ),
        &instance->core
    );
    EN_SceneModeConstruct(
        (EN_SceneMode*)(
            &instance->modes[EN_ENUMS_ENGINE_MODE_SCENE]
        ),
        &instance->core
    );

    /** Everything fine? Then we go directly to the running: */
    instance->core.basics.flags_bits.running = true;
    instance->core.basics.current_mode = 0;
}

void
EN_InstanceDestruct(
    EN_Instance* instance
)
{
    /** We destruct the modes: */
    EN_InitializationModeDestruct(
        (EN_InitializationMode*)(
            &instance->modes[EN_ENUMS_ENGINE_MODE_INITIALIZATION]
        )
    );
    EN_SceneModeDestruct(
        (EN_SceneMode*)(
            &instance->modes[EN_ENUMS_ENGINE_MODE_SCENE]
        )
    );

    /** See, finally destroy this: */
    EN_CoreDestruct(&instance->core);
}

void
EN_InstanceTick(
    EN_Instance* instance
)
{
    /** Should we do the tick? or skip it entirely? */
    if(instance->core.basics.flags_bits.skip_tick)
    {
        instance->core.basics.flags_bits.skip_tick = false;
        
    }
    else
    {
        EN_ModeTick(&instance->modes[instance->core.basics.current_mode]);
        instance->core.basics.tick_counter++;
    }
}

void
EN_InstanceDraw(
    EN_Instance* instance
)
{
    /**
     * NOTE: Skip draw is persistant, unlike skip_tick, you can stop drawing
     * for an long time, you can control it by internal event:
     *      `EN_ToggleSkipDraw` (which can toggle it);
     *      `EN_GetSkipDraw`    (which can get if we are skipping or not).
     *      `EN_SetSkipDraw`    (which sets if we are skipping drawing).
     */
    if(!(instance->core.basics.flags_bits.skip_draw))
    {
        EN_ModeDraw(
            &instance->modes[instance->core.basics.current_mode]
        );
        /** Increment the draw counter. */
        instance->core.basics.draw_counter++;
    }
}

void
EN_InstanceLoop(
    EN_Instance* instance
)
{
    while((instance->core.basics.flags_bits.running))
    {
        EN_InstanceTick(instance);
        EN_InstanceDraw(instance);
    }
}