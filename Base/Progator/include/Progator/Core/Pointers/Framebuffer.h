/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersFramebuffer_h
#define PGCorePointersFramebuffer_h

#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Core/Base.h"

typedef
void*
(*PG_PointersFramebufferNewFunction)();

typedef
void
(*PG_PointersFramebufferDestroyFunction)(
    void* mesh
);

typedef
PG_Result
(*PG_PointersFramebufferConstructFunction)(
    PG_Base* base,
    void* renderer,
    void* framebuffer,
    const PG_ViewportGeometry viewport_geometry
);

typedef
void
(*PG_PointersFramebufferDestructFunction)(
    PG_Base* base,
    void* renderer,
    void* framebuffer
);

typedef
void
(*PG_PointersFramebufferUseFunction)(
    PG_Base* base,
    void* renderer,
    void* framebuffer
);

typedef
void
(*PG_PointersFramebufferLeaveFunction)(
    PG_Base* base,
    void* renderer,
    void* framebuffer
);

typedef
void
(*PG_PointersFramebufferBeTextureFunction)(
    PG_Base* base,
    void* renderer,
    void* framebuffer,
    const PG_U8 slot
);

#endif