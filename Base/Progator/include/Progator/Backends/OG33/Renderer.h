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
#include "Progator/SDL.h"

typedef struct PG_BackendsOG33Renderer
{
    /** Context and the window we are attached to. */
    SDL_GLContext context;
    PG_BackendsOG33Window* using_window;

    /** Set the current buffers to clean. */
    PG_U32 cleaning_buffers;
} PG_BackendsOG33Renderer;

PG_BackendsOG33Renderer* PG_BackendsOG33RendererNew();
void PG_BackendsOG33RendererDestroy(PG_BackendsOG33Renderer* renderer);
PG_Result PG_BackendsOG33RendererConstruct(PG_Base* base, PG_BackendsOG33Window* window, PG_BackendsOG33Renderer* renderer);
void PG_BackendsOG33RendererDestruct(PG_Base* base, PG_BackendsOG33Window* window, PG_BackendsOG33Renderer* renderer);
void PG_BackendsOG33RendererSetViewport(PG_Base* base, PG_BackendsOG33Renderer* renderer, const PG_ViewportGeometry viewport_geometry);
void PG_BackendsOG33RendererDraw(PG_Base* base, PG_BackendsOG33Renderer* renderer);
void PG_BackendsOG33RendererClear(PG_Base* base, PG_BackendsOG33Renderer* renderer, const PG_U32 rgba_color);
void PG_BackendsOG33RendererEnableFeature(PG_Base* base, PG_BackendsOG33Renderer* renderer, const PG_U8 feature);
void PG_BackendsOG33RendererDisableFeature(PG_Base* base, PG_BackendsOG33Renderer* renderer, const PG_U8 feature);

#endif