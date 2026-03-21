/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Progator/Core/Base.h"
#include "Progator/Redirects.h"

PG_Base*
PG_BaseNew()
{
    PG_Base* new_base =
        (PG_Base*)(
            NK_AllocatorGet(sizeof(PG_Base))
        );
    return new_base;
}

void PG_BaseFree(
    PG_Base* base
)
{
    NK_AllocatorFree(base);
}

void
PG_BaseConstruct(
    PG_Base* base,
    NK_Validator* validator
)
{
    base->validator = validator;
}

void PG_BaseDestruct(
    PG_Base* base
)
{
    /** TODO: This function doesn't anything: */
    return;
}