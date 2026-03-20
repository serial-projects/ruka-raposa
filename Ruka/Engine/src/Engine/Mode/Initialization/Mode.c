/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Mode/Initialization/Mode.h"
#include "Engine/Redirects/NK.h"
#include "Engine/Enums.h"

EN_InitializationMode*
EN_InitializationModeNew()
{
    EN_InitializationMode* new_mode =
        (EN_InitializationMode*)(
            NK_AllocatorGet(sizeof(EN_InitializationMode))
        );
    return new_mode;
}

void
EN_InitializationModeFree(
    EN_InitializationMode* mode
)
{
    NK_AllocatorFree(mode);
}

void
EN_InitializationModeConstruct(
    EN_InitializationMode* mode,
    EN_Core* linking_core
)
{
    mode->linked_core = linking_core;
}

void
EN_InitializationModeDestruct(
    EN_InitializationMode* mode
)
{
    /** After saving and all ... */
    mode->linked_core = NULL;
}

void
EN_InitializationModeTick(
    EN_InitializationMode* mode
)
{
    /** NOTE: Begin the pipeline: */
    mode->linked_core->basics.current_mode = EN_ENUMS_ENGINE_MODE_SCENE;
}

void
EN_InitializationModeDraw(
    EN_InitializationMode* mode
)
{
    /** NOTE: Begin the pipeline (on Slugs): */
    return;
}
