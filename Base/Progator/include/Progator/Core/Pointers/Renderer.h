/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersRenderer_h
#define PGCorePointersRenderer_h

#include "Progator/Types/Basics.h"
#include "Progator/Core/Base.h"

typedef
void*
(*PG_PointersRendererNewFunction)();

typedef
void
(*PG_PointersRendererFreeFunction)(
    void* renderer
);

typedef
PG_Result
(*PG_PointersRendererConstructFunction)(
    void* renderer,
    void* window
);

typedef
void
(*PG_PointersRendererDestructFunction)(
    void* renderer
);

typedef
void
(*PG_PointersRendererSetViewportFunction)(
    void* renderer,
    const PG_U16 width,
    const PG_U16 height,
    const PG_U16 x_position,
    const PG_U16 y_position
);

typedef
void
(*PG_PointersRendererDrawFunction)(
    void* renderer
);

typedef
void
(*PG_PointersRendererClearFunction)(
    void* renderer,
    const PG_U32 rgba_color
);

typedef
void
(*PG_PointersRendererEnableFeatureFunction)(
    void* renderer,
    const PG_U8 feature
);

typedef
void
(*PG_PointersRendererDisableFeatureFunction)(
    void* renderer,
    const PG_U8 feature
);

#endif