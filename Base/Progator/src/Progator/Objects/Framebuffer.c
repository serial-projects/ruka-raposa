/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Framebuffer.h"

PG_Framebuffer* PG_FramebufferNew()
{
    PG_Framebuffer* new_framebuffer =
        (PG_Framebuffer*)(NK_malloc(sizeof(PG_Framebuffer)));
    return new_framebuffer;
}

void PG_FramebufferDestroy(
    PG_Framebuffer* framebuffer
)
{
    NK_free(framebuffer);
}

PG_Result PG_FramebufferConstruct(
    PG_Renderer* renderer,
    PG_Framebuffer* framebuffer,
    const PG_ViewportGeometry viewport_geometry
)
{
    framebuffer->renderer = renderer;
    framebuffer->backend_object = 
        framebuffer->
            renderer->
            window->
            pointers->
            framebuffer_new();
    return 
        framebuffer->
            renderer->
            window->
            pointers->
            framebuffer_construct(
                framebuffer->
                    renderer->
                    window->
                    base,
                framebuffer->
                    renderer->
                    backend_object,
                framebuffer->backend_object,
                viewport_geometry
            );
}

void PG_FramebufferDestruct(
    PG_Framebuffer* framebuffer
)
{
    framebuffer->
        renderer->
        window->
        pointers->
        framebuffer_destruct(
            framebuffer->
                renderer->
                window->
                base,
            framebuffer->
                renderer->
                backend_object,
            framebuffer->backend_object
        );
    framebuffer->
        renderer->
        window->
        pointers->
        framebuffer_destroy(
            framebuffer->backend_object
        );
}

void PG_FramebufferUse(
    PG_Framebuffer* framebuffer
)
{
    framebuffer->
        renderer->
        window->
        pointers->
        framebuffer_use(
            framebuffer->
                renderer->
                window->
                base,
            framebuffer->
                renderer->
                backend_object,
            framebuffer->backend_object
        );
}

void PG_FramebufferLeave(
    PG_Framebuffer* framebuffer
)
{
    framebuffer->
        renderer->
        window->
        pointers->
        framebuffer_leave(
            framebuffer->
                renderer->
                window->
                base,
            framebuffer->
                renderer->
                backend_object,
            framebuffer->backend_object
        );
}

void PG_FramebufferBeTexture(
    PG_Framebuffer* framebuffer,
    const PG_U8 slot
)
{
    framebuffer->
        renderer->
        window->
        pointers->
        framebuffer_be_texture(
            framebuffer->
                renderer->
                window->
                base,
            framebuffer->
                renderer->
                backend_object,
            framebuffer->backend_object,
            slot
        );
}