/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGBackendsOG33Renderer_h
#define PGBackendsOG33Renderer_h

#include "Progator/Backends/OG33/Window.h"
#include "Progator/Backends/OG33/GL.h"
#include "Progator/Backends/OG33/Types.h"
#include "Progator/Core/Base.h"
#include "Progator/Redirects.h"

typedef struct PG_BackendsOG33Renderer
{
    /**
     * @brief This contains the current context we are attached (running) into,
     * in OpenGL, it *seems* that each context is indepedent, but this is no
     * problem for us, we only use one.
     */
    SDL_GLContext context;

    /**
     * @brief We need to point to the window.
     */
    PG_BackendsOG33Window* using_window;

    /**
     * @brief Contains what we are cleaning, in OpenGL, we can clean stencil
     * and disable color depth, this is good for when we are dealing with UI
     * for example, when ZTEST is not useful (we do Z on UI by rendering order).
     */
    PG_U32 cleaning_buffers;
} PG_BackendsOG33Renderer;

PG_BackendsOG33Renderer*
PG_BackendsOG33RendererNew();

void
PG_BackendsOG33RendererDestruct(
    PG_BackendsOG33Renderer* renderer
);

PG_Result
PG_BackendsOG33RendererConstruct(
    PG_Base* base,
    PG_BackendsOG33Window* window,
    PG_BackendsOG33Renderer* renderer
);

void
PG_BackendsOG33RendererDestruct(
    PG_Base* base,
    PG_BackendsOG33Window* window,
    PG_BackendsOG33Renderer* renderer
);

void
PG_BackendsOG33RendererSetViewport(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    const PG_U16 width,
    const PG_U16 height,
    const PG_U16 x_position,
    const PG_U16 y_position
);

void
PG_BackendsOG33RendererDraw(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer
);

void
PG_BackendsOG33RendererClear(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    const PG_U32 rgba_color
);

void
PG_BackendsOG33RendererEnableFeature(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    const PG_U8 feature
);

void
PG_BackendsOG33RendererDisableFeature(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    const PG_U8 feature
);

#endif