/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef ENModeInitializationImplementation_h
#define ENModeInitializationImplementation_h

#include "Engine/Mode/Base.h"
#include "Engine/Core.h"

/**
 * @brief Contains the generic interface for mode for `EN_InitializationMode`
 */
typedef EN_Mode EN_InitializationModeImplementation;

/**
 * @brief Creates an new `EN_InitializationModeImplementation`
 */
EN_InitializationModeImplementation*
EN_InitializationModeImplementationNew();

/**
 * @brief Frees an `EN_InitializationModeImplementation` created by 
 * `EN_InitializationModeImplementationNew`.
 */
void
EN_InitializationModeImplementationFree(
    EN_InitializationModeImplementation* implementation
);

/**
 * @brief Constructs an `EN_InitializationModeImplementation`
 */
void
EN_InitializationModeImplementationConstruct(
    EN_InitializationModeImplementation* implementation,
    EN_Core* linking_core
);

/**
 * @brief Destructs an `EN_InitializationModeImplementation`
 */
void
EN_InitializationModeImplementationDestruct(
    EN_InitializationModeImplementation* implementation
);

#endif