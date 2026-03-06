/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef ENModeSceneMode_h
#define ENModeSceneMode_h

#include "Engine/Types/Basics.h"
#include "Engine/Core.h"

/**
 * @brief Contains everything the game is currently using (either for draw or
 * tick), like UI and more.
 */
typedef struct EN_SceneMode
{
    /**
     * @brief The core we are linked to (so we don't need to pass the core as
     * a parameter).
     */
    EN_Core* linked_core;
} EN_SceneMode;

/**
 * @brief Creates an new `EN_SceneMode` on the heap.
 */
EN_SceneMode*
EN_SceneModeNew();

/**
 * @brief Frees an `EN_SceneMode` created by `EN_SceneModeNew` function.
 */
void
EN_SceneModeFree(
    EN_SceneMode* mode
);

/**
 * @brief Constructs the `EN_SceneMode`
 */
void
EN_SceneModeConstruct(
    EN_SceneMode* mode,
    EN_Core* linking_core
);

/**
 * @brief Destructs the `EN_SceneMode`
 */
void
EN_SceneModeDestruct(
    EN_SceneMode* mode
);

/**
 * @brief Tick Stage of the Engine.
 */
void
EN_SceneModeTick(
    EN_SceneMode* mode
);

/**
 * @brief Draw Stage of the Engine.
 */
void
EN_SceneModeDraw(
    EN_SceneMode* mode
);

#endif