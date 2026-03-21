/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Engine.h"
#include "Engine/Redirects/NK.h"

void
EN_Init()
{
    if(!NK_IsInitialized())
    {
        NK_Init();
    }
    if(!PG_IsConstructed())
    {
        /** Ruka can't run with a non-initialized Progator. */
        if(!PG_Construct())
        {
            NK_Panic(
                "%s: PG could not initialize due = %s",
                NK_CURRENT_WHERE,
                SDL_GetError()
            );
        }
    }
}

void
EN_Quit()
{
    if(NK_IsInitialized())
    {
        NK_Quit();
    }
    if(PG_IsConstructed())
    {
        PG_Destruct();
    }
}