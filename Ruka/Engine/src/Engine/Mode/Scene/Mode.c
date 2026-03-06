/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Mode/Scene/Mode.h"
#include "Engine/Redirects/NK.h"

EN_SceneMode*
EN_SceneModeNew()
{
    EN_SceneMode* new_mode =
        (EN_SceneMode*)(
            NK_AllocatorGet(sizeof(EN_SceneMode))
        );
    return new_mode;
}

void
EN_SceneModeFree(
    EN_SceneMode* mode
)
{
    NK_AllocatorFree(mode);
}

void
EN_SceneModeConstruct(
    EN_SceneMode* mode,
    EN_Core* linking_core
)
{
    mode->linked_core = linking_core;
}

void
EN_SceneModeDestruct(
    EN_SceneMode* mode
)
{
    /** After saving and all ... */
    mode->linked_core = NULL;
}

void
EN_SceneModeTick(
    EN_SceneMode* mode
)
{
    /** NOTE: Begin the pipeline: */    
}

void
EN_SceneModeDraw(
    EN_SceneMode* mode
)
{
    /** NOTE: Begin the pipeline (on Slugs): */
}
