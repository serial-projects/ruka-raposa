/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef ENModeInitializationMode_h
#define ENModeInitializationMode_h

#include "Engine/Types/Basics.h"
#include "Engine/Core.h"

/**
 * @brief This is a default early mode to load everything of the engine before
 * the `EN_SceneMode`, not that this mode is required, nothing is require on
 * Ruka Engine, but this is important to load the manifests, mods and more, the
 * game might not be found or be executable.
 */
typedef struct EN_InitializationMode
{
    /**
     * @brief The core we are linked to (so we don't need to pass the core as
     * a parameter).
     */
    EN_Core* linked_core;
} EN_InitializationMode;

/**
 * @brief Creates an new `EN_InitializationMode` on the heap.
 */
EN_InitializationMode*
EN_InitializationModeNew();

/**
 * @brief Frees an `EN_InitializationMode` created by `EN_InitializationModeNew` function.
 */
void
EN_InitializationModeFree(
    EN_InitializationMode* mode
);

/**
 * @brief Constructs the `EN_InitializationMode`
 */
void
EN_InitializationModeConstruct(
    EN_InitializationMode* mode,
    EN_Core* linking_core
);

/**
 * @brief Destructs the `EN_InitializationMode`
 */
void
EN_InitializationModeDestruct(
    EN_InitializationMode* mode
);

/**
 * @brief Tick Stage of the Engine.
 */
void
EN_InitializationModeTick(
    EN_InitializationMode* mode
);

/**
 * @brief Draw Stage of the Engine.
 */
void
EN_InitializationModeDraw(
    EN_InitializationMode* mode
);

#endif