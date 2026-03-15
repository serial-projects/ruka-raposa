/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersRenderer_h
#define PGCorePointersRenderer_h

#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Core/Base.h"

typedef
void*
(*PG_PointersRendererNewFunction)();

typedef
void
(*PG_PointersRendererDestroyFunction)(
    void* window
);

typedef
PG_Result
(*PG_PointersRendererConstructFunction)(
    PG_Base* base,
    void* window,
    void* renderer
);

typedef
void
(*PG_PointersRendererDestructFunction)(
    PG_Base* base,
    void* window,
    void* renderer
);

typedef
void
(*PG_PointersRendererSetViewportFunction)(
    PG_Base* base,
    void* renderer,
    const PG_ViewportGeometry viewport_geometry
);

typedef
void
(*PG_PointersRendererDrawFunction)(
    PG_Base* base,
    void* renderer
);

typedef
void
(*PG_PointersRendererClearFunction)(
    PG_Base* base,
    void* renderer,
    const PG_U32 rgba_color
);

typedef
void
(*PG_PointersRendererEnableFeatureFunction)(
    PG_Base* base,
    void* renderer,
    const PG_U8 feature
);

typedef
void
(*PG_PointersRendererDisableFeatureFunction)(
    PG_Base* base,
    void* renderer,
    const PG_U8 feature
);

#endif