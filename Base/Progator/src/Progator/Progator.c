/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Progator/Progator.h"

/**
 * @brief This is a global to keep track of the current state of the things, so
 * we don't need to initialize this multiple times.
 */
static
PG_Boolean PG_Initialized = false;

PG_Result
PG_Construct()
{
    PG_Result good = true;
    if(! PG_Initialized)
    {
        /** TODO: Set the memory functions for SDL based on NK. */
        SDL_SetAppMetadata(
            "Ruka Raposa Engine",
            "1.0.0-Alpha(1)",
            "io.rukaraposa.engine"
        );
        SDL_SetAppMetadataProperty(
            SDL_PROP_APP_METADATA_CREATOR_STRING,
            "Ruka Raposa Team"
        );
        good =
            SDL_Init(
                SDL_INIT_EVENTS |
                SDL_INIT_VIDEO  |
                SDL_INIT_AUDIO
            );
        PG_Initialized = true;
    }
    return good;
}

void
PG_Destruct()
{
    if(PG_Initialized)
    {
        /** Shutdown SDL here. */
        SDL_Quit();
    }
}

const PG_Result
PG_IsConstructed()
{
    return PG_Initialized;
}