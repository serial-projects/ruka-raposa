/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Backends/OG33/Framebuffer.h"

PG_BackendsOG33Framebuffer*
PG_BackendsOG33FramebufferNew()
{
    PG_BackendsOG33Framebuffer* new_framebuffer =
        (PG_BackendsOG33Framebuffer*)(
            NK_AllocatorGet(sizeof(PG_BackendsOG33Framebuffer))
        );
    return new_framebuffer;
}

void
PG_BackendsOG33FramebufferDestruct(
    PG_BackendsOG33Framebuffer* framebuffer
)
{
    NK_AllocatorFree(framebuffer);
}

PG_Result
PG_BackendsOG33FramebufferConstruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Framebuffer* framebuffer,
    const PG_U16 width,
    const PG_U16 height
)
{
    GLenum status;

    /** We generate the framebuffer here: */
    glGenFramebuffers(1, &framebuffer->FBO);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->FBO);
    
    /** We generate the texture: */
    glGenTextures(1, &framebuffer->FB_texture);
    glBindTexture(GL_TEXTURE_2D, framebuffer->FB_texture);

    /** NOTE: We do need to create an empty texture: */
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA8,
        width,
        height,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        NULL
    );

    /** We set the default parameters for any texture: */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    /** We say to the framebuffer that this is the output we want: */
    glFramebufferTexture2D(
        GL_FRAMEBUFFER,
        GL_COLOR_ATTACHMENT0,
        GL_TEXTURE_2D,
        framebuffer->FB_texture,
        0
    );

    /** Now we create an rendering buffer: */
    glGenRenderbuffers(1, &framebuffer->RBO);
    glBindRenderbuffer(1, framebuffer->RBO);

    /** We define the parameters for the RBO: */
    glRenderbufferStorage(
        GL_RENDERBUFFER,
        GL_DEPTH24_STENCIL8,
        width,
        height
    );

    glFramebufferRenderbuffer(
        GL_FRAMEBUFFER,
        GL_DEPTH_STENCIL_ATTACHMENT,
        GL_RENDERBUFFER,
        framebuffer->RBO
    );

    /** We need to check for the status: */
    status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if(status != GL_FRAMEBUFFER_COMPLETE)
    {
        glDeleteRenderbuffers(1, &framebuffer->RBO);
        glDeleteFramebuffers(1, &framebuffer->FBO);
        glDeleteTextures(1, &framebuffer->FB_texture);
        return false;
    }

    /** Set the framebuffer to zero, we don't want to use, now. */
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    return true;
}

void
PG_BackendsOG33FramebufferDestruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Framebuffer* framebuffer
)
{
    glDeleteFramebuffers(1, &framebuffer->FBO);
    glDeleteRenderbuffers(1, &framebuffer->RBO);
    glDeleteTextures(1, &framebuffer->FB_texture);
}

void
PG_BackendsOG33FramebufferUse(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Framebuffer* framebuffer
)
{
    glBindRenderbuffer(GL_RENDERBUFFER, framebuffer->RBO);
    glBindFramebuffer(GL_FRAMEBUFFER, framebuffer->FBO);
}

void
PG_BackendsOG33FramebufferLeave(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Framebuffer* framebuffer
)
{
    glBindRenderbuffer(GL_RENDERBUFFER, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void
PG_BackendsOG33FramebufferBeTexture(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Framebuffer* framebuffer,
    const PG_U8 slot
)
{

    glBindTexture(GL_TEXTURE_2D, framebuffer->FB_texture);
    glActiveTexture(GL_TEXTURE0 + slot);
}
