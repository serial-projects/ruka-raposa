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

NK_Result
PG_BaseConstruct(
    PG_Base* base,
    NK_Validator* validator
)
{
    NK_Result initialized;
    base->validator = validator;

    /**
     * TODO: This gives an internal hint to what we are, but in the future, we
     * should allow the game maker to also make their internal hints as well!
     */
    SDL_SetAppMetadata(
        "Ruka Raposa Engine",
        "1.0.0-Alpha(1)",
        "io.rukaraposa.engine"
    );
    SDL_SetAppMetadataProperty(
        SDL_PROP_APP_METADATA_CREATOR_STRING,
        "Ruka Raposa Team"
    );
    
    /** We initialize SDL here: */
    initialized =
        SDL_Init(
            SDL_INIT_EVENTS |
            SDL_INIT_VIDEO  |
            SDL_INIT_AUDIO
        );

    if(!initialized)
    {
        NK_ValidatorPushMessage(
            base->validator,
            NK_VALIDATOR_LEVEL_ERROR,
            "Failed to initialize SDL due: %s",
            SDL_GetError()
        );
    }
    else
    {
        NK_ValidatorPushMessage(
            base->validator,
            NK_VALIDATOR_LEVEL_DEBUG,
            "Initialized SDL, version = %d",
            SDL_GetVersion()
        );
    }
    return initialized;
}

void PG_BaseDestruct(
    PG_Base* base
)
{
    /** TODO: This function doesn't anything: */
    return;
}