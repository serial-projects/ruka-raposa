/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Renderer.h"

PG_Renderer* PG_RendererNew()
{
    PG_Renderer* new_renderer =
        (PG_Renderer*)(
            NK_AllocatorGet(sizeof(PG_Renderer))
        );
    return new_renderer;
}

void PG_RendererFree(
    PG_Renderer* renderer
)
{
    NK_AllocatorFree(renderer);
}

PG_Result PG_RendererConstruct(
    PG_Renderer* renderer,
    PG_Window* use_window
)
{
    renderer->window = use_window;
    renderer->backend_object = 
        renderer->
            window->
            pointers->
            renderer_new();
    return 
        renderer->
        window->
        pointers->
        renderer_construct(
            renderer->window->base,
            renderer->window->backend_object,
            renderer->backend_object
        );
}

void PG_RendererDestruct(
    PG_Renderer* renderer
)
{
    renderer->
        window->
        pointers->
        renderer_destruct(
            renderer->window->base,
            renderer->window->backend_object,
            renderer->backend_object
        );
    renderer->
        window->
        pointers->
        renderer_free(renderer->backend_object);
}

void PG_RendererSetViewport(
    PG_Renderer* renderer,
    const PG_ViewportGeometry viewport_geometry
)
{
    renderer->
        window->
        pointers->
        renderer_set_viewport(
            renderer->window->base,
            renderer->backend_object,
            viewport_geometry
        );
}

void PG_RendererDraw(
    PG_Renderer* renderer
)
{
    renderer->
        window->
        pointers->
        renderer_draw(
            renderer->window->base,
            renderer->backend_object
        );
}

void PG_RendererClear(
    PG_Renderer* renderer,
    const PG_U32 rgba_color
)
{
    renderer->
        window->
        pointers->
        renderer_clear(
            renderer->window->base,
            renderer->backend_object,
            rgba_color
        );
}

void PG_RendererEnableFeature(
    PG_Renderer* renderer,
    const PG_U8 feature
)
{
    renderer->
        window->
        pointers->
        renderer_enable_feature(
            renderer->window->base,
            renderer->backend_object,
            feature
        );
}

void PG_RendererDisableFeature(
    PG_Renderer* renderer,
    const PG_U8 feature
)
{
    renderer->
        window->
        pointers->
        renderer_disable_feature(
            renderer->window->base,
            renderer->backend_object,
            feature
        );
}