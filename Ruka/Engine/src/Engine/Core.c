/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Core.h"
#include "Engine/Mode.h"
#include "Engine/Redirects/NK.h"

EN_Core*
EN_CoreNew()
{
    EN_Core* new_core =
        (EN_Core*)(
            NK_AllocatorGet(sizeof(EN_Core))
        );
    return new_core;
}

void
EN_CoreFree(
    EN_Core* core
)
{
    NK_AllocatorFree(core);
}

EN_Result
EN_CoreConstruct(
    EN_Core* core
)
{
    EN_Result good;
    EN_CoreBasicsConstruct(&core->basics);
    good =
        EN_CoreGraphicsConstruct(
            &core->graphics,
            &core->basics.master_validator,
            PG_ENUMS_BACKEND_OPENGL_33C
        );
    if(!good)
    {
        /**
         * NOTE: This only happens when the window creation resulted in complete
         * failure.
         */
        goto core_graphics_failed_ending;
    }
core_graphics_failed_ending:
    return good;
}

void
EN_CoreDestruct(
    EN_Core* core
)
{
    EN_CoreGraphicsDestruct(&core->graphics);
    EN_CoreBasicsDestruct(&core->basics);
}