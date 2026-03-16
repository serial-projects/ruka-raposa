/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGBackendsOG33Framebuffer_h
#define PGBackendsOG33Framebuffer_h

#include "Progator/Backends/OG33/Config.h"
#include "Progator/Backends/OG33/GL.h"
#include "Progator/Backends/OG33/Types.h"
#include "Progator/Backends/OG33/Renderer.h"
#include "Progator/Core/Base.h"

typedef struct PG_BackendsOG33Framebuffer
{
    /**
     * @brief Holds an reference for the renderer.
     */
    PG_BackendsOG33Renderer* renderer;

    /**
     * @brief FBO = Framebuffer Object.
     */
    PG_BackendsOG33FramebufferHandle FBO;

    /**
     * @brief RBO = Renderbuffer Object.
     */
    PG_BackendsOG33RenderbufferHandle RBO;

    /**
     * @brief Holds an texture handler (the part where we need to
     * `PG_FramebufferBeTexture`).
     */
    PG_BackendsOG33FramebufferTextureHandle FB_texture;
} PG_BackendsOG33Framebuffer;

PG_BackendsOG33Framebuffer*
PG_BackendsOG33FramebufferNew();

void
PG_BackendsOG33FramebufferFree(
    PG_BackendsOG33Framebuffer* framebuffer
);

PG_Result
PG_BackendsOG33FramebufferConstruct(
    PG_BackendsOG33Framebuffer* framebuffer,
    PG_BackendsOG33Renderer* renderer,
    const PG_U16 width,
    const PG_U16 height
);

void
PG_BackendsOG33FramebufferDestruct(
    PG_BackendsOG33Framebuffer* framebuffer
);

void
PG_BackendsOG33FramebufferUse(
    PG_BackendsOG33Framebuffer* framebuffer
);

void
PG_BackendsOG33FramebufferLeave(
    PG_BackendsOG33Framebuffer* framebuffer
);

void PG_BackendsOG33FramebufferBeTexture(
    PG_BackendsOG33Framebuffer* framebuffer,
    const PG_U8 slot
);

#endif