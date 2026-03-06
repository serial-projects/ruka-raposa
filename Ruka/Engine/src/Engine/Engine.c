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
}

void
EN_Quit()
{
    if(NK_IsInitialized())
    {
        NK_Quit();
    }
}