/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Renderer.h"

PG_Renderer*
PG_RendererNew()
{
    PG_Renderer* new_renderer = 
        (PG_Renderer*)(
            NK_AllocatorGet(sizeof(PG_Renderer))
        );
    return new_renderer;
}

void
PG_RendererFree(
    PG_Renderer* renderer
)
{
    NK_AllocatorFree(renderer);
}

PG_Result
PG_RendererConstruct(
    PG_Renderer* renderer,
    PG_Window* window
)
{
    renderer->window = window;
    renderer->pointers = window->pointers;
    renderer->base = window->base;
    renderer->backend_object = renderer->pointers->renderer_new();
    return (
        renderer->pointers->renderer_construct(
            renderer->backend_object,
            renderer->window->backend_object
        )
    );
}

void
PG_RendererDestruct(
    PG_Renderer* renderer
)
{
    renderer->pointers->renderer_destruct(
        renderer->backend_object
    );
    renderer->pointers->renderer_free(
        renderer->backend_object
    );
}

void
PG_RendererSetViewport(
    PG_Renderer* renderer,
    const PG_U16 width,
    const PG_U16 height,
    const PG_U16 x_position,
    const PG_U16 y_position
)
{
    renderer->pointers->renderer_set_viewport(
        renderer->backend_object,
        width,
        height,
        x_position,
        y_position
    );
}

void
PG_RendererDraw(
    PG_Renderer* renderer
)
{
    renderer->pointers->renderer_draw(
        renderer->backend_object
    );
}

void
PG_RendererClear(
    PG_Renderer* renderer,
    const PG_U32 rgba_color
)
{
    renderer->pointers->renderer_clear(
        renderer->backend_object,
        rgba_color
    );
}

void
PG_RendererEnableFeature(
    PG_Renderer* renderer,
    const PG_U8 feature
)
{
    renderer->pointers->renderer_enable_feature(
        renderer->backend_object,
        feature
    );
}

void
PG_RendererDisableFeature(
    PG_Renderer* renderer,
    const PG_U8 feature
)
{
    renderer->pointers->renderer_disable_feature(
        renderer->backend_object,
        feature
    );
}