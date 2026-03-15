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

/**
 * @brief This should set the size of the window.
 */
typedef
void(*RG_BackendWindowSetSize)(
    void* window,
    const RG_WindowSize width,
    const RG_WindowSize height
);

/**
 * @brief This should set the title of the window.
 */
typedef
void(*RG_BackendWindowSetTitle)(
    void* window,
    const RG_WindowTitle title
);

/**
 * @brief This should tell the window to draw.
 */
typedef
void(*RG_BackendWindowDraw)(
    void* window
);

#endif