/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Framebuffer.h"

PG_Framebuffer*
PG_FramebufferNew()
{
    PG_Framebuffer* new_framebuffer =
        (PG_Framebuffer*)(
            NK_AllocatorGet(sizeof(PG_Framebuffer))
        );
    return new_framebuffer;
}

void
PG_FramebufferFree(
    PG_Framebuffer* framebuffer
)
{
    NK_AllocatorFree(framebuffer);
}

PG_Result
PG_FramebufferConstruct(
    PG_Framebuffer* framebuffer,
    PG_Renderer* renderer,
    const PG_U16 width,
    const PG_U16 height,
    const PG_U16 x_position,
    const PG_U16 y_position
)
{
    framebuffer->renderer = renderer;
    framebuffer->backend_object =
        framebuffer->renderer->pointers->framebuffer_new();
    return (
        framebuffer->renderer->pointers->framebuffer_construct(
            framebuffer->backend_object,
            framebuffer->renderer->backend_object,
            width,
            height,
            x_position,
            y_position
        )
    );
}

void
PG_FramebufferDestruct(
    PG_Framebuffer* framebuffer
)
{
    framebuffer->renderer->pointers->framebuffer_destruct(
        framebuffer->backend_object
    );
    framebuffer->renderer->pointers->framebuffer_free(
        framebuffer->backend_object
    );
}

void
PG_FramebufferUse(
    PG_Framebuffer* framebuffer
)
{
    framebuffer->renderer->pointers->framebuffer_use(
        framebuffer->backend_object
    );
}

void
PG_FramebufferLeave(
    PG_Framebuffer* framebuffer
)
{
    framebuffer->renderer->pointers->framebuffer_leave(
        framebuffer->backend_object
    );
}

void
PG_FramebufferBeTexture(
    PG_Framebuffer* framebuffer,
    const PG_U8 slot
)
{
    framebuffer->renderer->pointers->framebuffer_be_texture(
        framebuffer->backend_object,
        slot
    );
}