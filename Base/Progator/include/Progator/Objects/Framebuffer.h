/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGObjectsFramebuffer_h
#define PGObjectsFramebuffer_h

#include "Progator/Core/Base.h"
#include "Progator/Core/Pointers.h"
#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Objects/Renderer.h"

typedef struct PG_Framebuffer
{
    void* backend_object;
    PG_Renderer* renderer;
} PG_Framebuffer;

PG_Framebuffer* PG_FramebufferNew();
void PG_FramebufferDestroy(PG_Framebuffer* framebuffer);
PG_Result PG_FramebufferConstruct(PG_Renderer* renderer, PG_Framebuffer* framebuffer, const PG_ViewportGeometry viewport_geometry);
void PG_FramebufferDestruct(PG_Framebuffer* framebuffer);
void PG_FramebufferUse(PG_Framebuffer* framebuffer);
void PG_FramebufferLeave(PG_Framebuffer* framebuffer);
void PG_FramebufferBeTexture(PG_Framebuffer* framebuffer, const PG_U8 slot);

#endif