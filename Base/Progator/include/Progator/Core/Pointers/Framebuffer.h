/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersFramebuffer_h
#define PGCorePointersFramebuffer_h

#include "Progator/Types/Basics.h"
#include "Progator/Core/Base.h"

typedef
void*
(*PG_PointersFramebufferNewFunction)();

typedef
void
(*PG_PointersFramebufferFreeFunction)(
    void* mesh
);

typedef
PG_Result
(*PG_PointersFramebufferConstructFunction)(
    void* framebuffer,
    void* renderer,
    const PG_U16 width,
    const PG_U16 height,
    const PG_U16 x_position,
    const PG_U16 y_position
);

typedef
void
(*PG_PointersFramebufferDestructFunction)(
    void* framebuffer
);

typedef
void
(*PG_PointersFramebufferUseFunction)(
    void* framebuffer
);

typedef
void
(*PG_PointersFramebufferLeaveFunction)(
    void* framebuffer
);

typedef
void
(*PG_PointersFramebufferBeTextureFunction)(
    void* framebuffer,
    const PG_U8 slot
);

#endif