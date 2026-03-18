/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Instance.h"
#include "Engine/Redirects/NK.h"
#include "Engine/Enums.h"

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
    /** Initialize the core: */
    EN_CoreConstruct(
        &instance->core
    );

    /** Initialize the modes: */
    EN_InitializationModeConstruct(
        &instance->initialization_mode,
        &instance->core
    );
    EN_SceneModeConstruct(
        &instance->scene_mode,
        &instance->core
    );

    /** Everything fine? Then we go directly to the running: */
    instance->core.basics.flags_bits.running = true;
}

void
EN_InstanceDestruct(
    EN_Instance* instance
)
{
    /** NOTE: We need to follow the order here: Everything -> Core! */
    EN_InitializationModeDestruct(
        &instance->initialization_mode
    );
    EN_SceneModeDestruct(
        &instance->scene_mode
    );

    /** See, finally destroy this: */
    EN_CoreDestruct(
        &instance->core
    );
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
        switch(instance->core.basics.current_mode)
        {
            case EN_ENUMS_ENGINE_MODE_INITIALIZATION:
                EN_InitializationModeTick(
                    &instance->initialization_mode
                );
                break;
            case EN_ENUMS_ENGINE_MODE_SCENE:
                EN_SceneModeTick(
                    &instance->scene_mode
                );
                break;
            default:
                NK_Panic(
                    "%s: Selected invalid mode: %d\n",
                    NK_CURRENT_WHERE,
                    (int)(instance->core.basics.current_mode)
                );
                break;
        };

        /** Increment on the tick counter here. */
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
        switch(instance->core.basics.current_mode)
        {
            case EN_ENUMS_ENGINE_MODE_INITIALIZATION:
                EN_InitializationModeDraw(
                    &instance->initialization_mode
                );
                break;
            case EN_ENUMS_ENGINE_MODE_SCENE:
                EN_SceneModeDraw(
                    &instance->scene_mode
                );
                break;
            default:
                NK_Panic(
                    "%s: Selected invalid mode: %d\n",
                    NK_CURRENT_WHERE,
                    (int)(instance->core.basics.current_mode)
                );
                break;
        };

        /** Increment the draw counter. */
        instance->core.basics.draw_counter++;
    }
}
