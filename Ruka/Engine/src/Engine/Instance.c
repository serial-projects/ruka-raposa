/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Instance.h"
#include "Engine/Redirects/NK.h"

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

}

void
EN_InstanceDraw(
    EN_Instance* instance
)
{
    
}
