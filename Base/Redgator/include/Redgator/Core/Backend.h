/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef RGCoreBackend_h
#define RGCoreBackend_h

#include "Redgator/Types.h"
#include "Redgator/Core/Backend/Window.h"

/**
 * @brief This is the connection with the backend implementations.
 */
typedef struct RG_Backend
{
    /* Window Functions: */

    RG_BackendWindowNew window_new;
    RG_BackendWindowFree window_free;
    RG_BackendWindowConstruct window_construct;
    RG_BackendWindowDestruct window_destruct;
    RG_BackendWindowSetSize window_set_size;
    RG_BackendWindowSetTitle window_set_title;

    /* Renderer Functions: */
} RG_Backend;

#endif