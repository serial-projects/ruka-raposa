/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Progator/Core/Base.h"
#include "Progator/SDL.h"

PG_Base* PG_BaseNew()
{
    PG_Base* new_base = NK_malloc(sizeof(PG_Base));
    return new_base;
}

void PG_BaseDestroy(
    PG_Base* base
)
{
    NK_free(base);
}

NK_Result PG_BaseConstruct(
    PG_Base* base,
    NK_Validator* use_validator
)
{
    base->attached_validator = use_validator;
    base->memory_used = 0;

    /** We give SDL an hint about what we are: */
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
    const NK_Result initialized =
        SDL_Init(
            SDL_INIT_EVENTS |
            SDL_INIT_VIDEO  |
            SDL_INIT_AUDIO
        );

    if(!initialized)
    {
        NK_ValidatorError(
            base->attached_validator,
            1,
            "Failed to initialize SDL due: %s",
            SDL_GetError()
        );
    }
    else
    {
        NK_ValidatorDebug(
            base->attached_validator,
            "Initialize SDL, version = %d",
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