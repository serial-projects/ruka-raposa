/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Core.h"
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

void
EN_CoreConstruct(
    EN_Core* core
)
{
    EN_CoreBasicsConstruct(&core->basics);
}

void
EN_CoreDestruct(
    EN_Core* core
)
{
    EN_CoreBasicsDestruct(&core->basics);
}