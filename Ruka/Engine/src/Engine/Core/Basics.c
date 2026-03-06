/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Core/Basics.h"
#include "Engine/Redirects/NK.h"

EN_CoreBasics*
EN_CoreBasicsNew()
{
    EN_CoreBasics* new_basics =
        (EN_CoreBasics*)(
            NK_AllocatorGet(sizeof(EN_CoreBasics))
        );
    return new_basics;
}

void
EN_CoreBasicsFree(
    EN_CoreBasics* basics
)
{
    NK_AllocatorFree(basics);
}

void
EN_CoreBasicsConstruct(
    EN_CoreBasics* basics
)
{
    /** NOTE: We can simply set everything to zero. */
    NK_RedirectMemset(
        basics,
        0,
        sizeof(EN_CoreBasics)
    );
}

void
EN_CoreBasicsDestruct(
    EN_CoreBasics* basics
)
{
    NK_RedirectMemset(
        basics,
        0,
        sizeof(EN_CoreBasics)
    );
}