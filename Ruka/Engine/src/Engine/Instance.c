/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Instance.h"
#include "Engine/Redirects/NK.h"
#include "Engine/Enums.h"
#include "Engine/Mode.h"

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

EN_Result
EN_InstanceConstruct(
    EN_Instance* instance
)
{
    EN_Result good;

    /** Construct the core: */
    good = EN_CoreConstruct(&instance->core);
    if(!good)
    {
        /** NOTE: Failed to initialize core, we can't proceed! */
        goto failed_construct_core_ending;
    }

    /** Report an "Hello World!" here: */
    NK_ValidatorPushMessage(
        &instance->core.basics.master_validator,
        NK_VALIDATOR_LEVEL_LOG,
        "%s: Hello World!\n",
        NK_CURRENT_WHERE
    );


    /** We construct the modes: */
    EN_InitializationModeImplementationConstruct(
        (EN_InitializationModeImplementation*)(
            &instance->modes[EN_ENUMS_ENGINE_MODE_INITIALIZATION]
        ),
        &instance->core
    );
    EN_SceneModeImplementationConstruct(
        (EN_SceneModeImplementation*)(
            &instance->modes[EN_ENUMS_ENGINE_MODE_SCENE]
        ),
        &instance->core
    );

    /** Everything fine? Then we go directly to the running: */
    instance->core.basics.flags_bits.running = true;
    instance->core.basics.current_mode = 0;
failed_construct_core_ending:
    return good;
}

void
EN_InstanceDestruct(
    EN_Instance* instance
)
{
    /** We destruct the modes: */
    EN_InitializationModeImplementationDestruct(
        (EN_InitializationModeImplementation*)(
            &instance->modes[EN_ENUMS_ENGINE_MODE_INITIALIZATION]
        )
    );
    EN_SceneModeImplementationDestruct(
        (EN_SceneModeImplementation*)(
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