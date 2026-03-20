/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef ENInstance_h
#define ENInstance_h

#include "Engine/Types/Basics.h"
#include "Engine/Core.h"
#include "Engine/Mode/Initialization/Mode.h"
#include "Engine/Mode/Scene/Mode.h"
#include "Engine/Enums.h"

/**
 * @brief Contains the actual instance that holds the mode the game is running
 * and more. If you so wanted to have two games on the same binary, this is the
 * way to do it.
 */
typedef struct EN_Instance
{
    /**
     * @brief Contains the core itself.
     */
    EN_Core core;

    /**
     * @brief Contains the modes:
     */
    EN_Mode modes[EN_ENUMS_ENGINE_MODE_QUANTITY];
} EN_Instance;

/**
 * @brief Creates an new `EN_Instance` on the heap.
 */
EN_Instance*
EN_InstanceNew();

/**
 * @brief Frees an `EN_Instance` created by `EN_InstanceNew` function.
 */
void
EN_InstanceFree(
    EN_Instance* instance
);

/**
 * @brief Construct `EN_Instance` modes and core.
 */
void
EN_InstanceConstruct(
    EN_Instance* instance
);

/**
 * @brief Destruct `EN_Instance`
 * 
 * @warning This doesn't imply saving the game, saving the game is a runtime
 * event of the `EN_SceneMode` layer!
 */
void
EN_InstanceDestruct(
    EN_Instance* instance
);

/** Tick & Draw: */

/**
 * @brief On the current mode, we tick the game.
 */
void
EN_InstanceTick(
    EN_Instance* instance
);

/**
 * @brief On the current mode, we draw the game.
 */
void
EN_InstanceDraw(
    EN_Instance* instance
);

/**
 * @brief This will lock the thread into executing the code until forever and
 * loop the game (until the game is active, although). This will loop everything
 * until it ends. This loop also controls the speed, game speed and more.
 */
void
EN_InstanceLoop(
    EN_Instance* instance
);

#endif