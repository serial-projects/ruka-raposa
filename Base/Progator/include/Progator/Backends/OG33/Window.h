/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGBackendsOG33Window_h
#define PGBackendsOG33Window_h

#include "Progator/Backends/OG33/GL.h"
#include "Progator/Backends/OG33/Types.h"
#include "Progator/Core/Base.h"
#include "Progator/Redirects.h"

typedef struct PG_BackendsOG33Window
{
    /**
     * @brief This contains the OS window, which is based on SDL.
     */
    SDL_Window* os_window;

    /**
     * @brief An quick access to the window ID.
     */
    PG_U32 id;
} PG_BackendsOG33Window;

PG_BackendsOG33Window*
PG_BackendsOG33WindowNew();

void
PG_BackendsOG33WindowDestroy(
    PG_BackendsOG33Window* window
);

NK_Result
PG_BackendsOG33WindowConstruct(
    PG_Base* base,
    PG_BackendsOG33Window* window
);

void
PG_BackendsOG33WindowDestruct(
    PG_Base* base,
    PG_BackendsOG33Window* window
);

void
PG_BackendsOG33WindowDraw(
    PG_Base* base,
    PG_BackendsOG33Window* window
);

void
PG_BackendsOG33WindowSetSize(
    PG_Base* base,
    PG_BackendsOG33Window* window,
    const NK_U16 width,
    const NK_U16 height
);

void
PG_BackendsOG33WindowSetTitle(
    PG_Base* base,
    PG_BackendsOG33Window* window,
    const PG_C8* title
);

#endif