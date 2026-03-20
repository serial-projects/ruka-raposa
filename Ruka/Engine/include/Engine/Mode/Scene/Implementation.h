/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef ENModeSceneImplementation_h
#define ENModeSceneImplementation_h

#include "Engine/Mode/Base.h"
#include "Engine/Core.h"

/**
 * @brief Contains the generic interface for mode for `EN_SceneMode`
 */
typedef EN_Mode EN_SceneModeImplementation;

/**
 * @brief Creates an new `EN_SceneModeImplementation`
 */
EN_SceneModeImplementation*
EN_SceneModeImplementationNew();

/**
 * @brief Frees an `EN_SceneModeImplementation` created by 
 * `EN_SceneModeImplementationNew`.
 */
void
EN_SceneModeImplementationFree(
    EN_SceneModeImplementation* implementation
);

/**
 * @brief Constructs an `EN_SceneModeImplementation`
 */
void
EN_SceneModeImplementationConstruct(
    EN_SceneModeImplementation* implementation,
    EN_Core* linking_core
);

/**
 * @brief Destructs an `EN_SceneModeImplementation`
 */
void
EN_SceneModeImplementationDestruct(
    EN_SceneModeImplementation* implementation
);

#endif