/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGObjectsRenderer_h
#define PGObjectsRenderer_h

#include "Progator/Core/Base.h"
#include "Progator/Core/Pointers.h"
#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Objects/Window.h"

typedef struct PG_Renderer
{
    void* backend_object;

    /** Each Renderer is attached to a single window: */
    PG_Window* window;
} PG_Renderer;

PG_Renderer* PG_RendererNew();
void PG_RendererDestroy(PG_Renderer* renderer);
PG_Result PG_RendererConstruct(PG_Renderer* renderer, PG_Window* use_window);
void PG_RendererDestruct(PG_Renderer* renderer);
void PG_RendererSetViewport(PG_Renderer* renderer, const PG_ViewportGeometry viewport_geometry);
void PG_RendererDraw(PG_Renderer* renderer);
void PG_RendererClear(PG_Renderer* renderer, const PG_U32 rgba_color);
void PG_RendererEnableFeature(PG_Renderer* renderer, const PG_U8 feature);
void PG_RendererDisableFeature(PG_Renderer* renderer, const PG_U8 feature);

#endif