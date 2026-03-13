/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef RGCoreBackendWindow_h
#define RGCoreBackendWindow_h

#include "Redgator/Core/Base.h"

/**
 * @brief This must be a funciton that returns an Window handler.
 */
typedef
void*(*RG_BackendWindowNew)();

/**
 * @brief This must be a function.
 */
typedef
void(*RG_BackendWindowFree)(
    void* window
);

/**
 * @brief This should construct the window.
 */
typedef
void(*RG_BackendWindowConstruct)(
    void* window,
    RG_Base* base
);

/**
 * @brief This should destruct the window.
 */
typedef
void(*RG_BackendWindowDestruct)(
    void* window
);

#endif