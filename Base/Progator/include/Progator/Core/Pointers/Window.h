/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersWindow_h
#define PGCorePointersWindow_h

#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Core/Base.h"

/** Every Function: */

typedef
void*
(*PG_PointersWindowNewFunction)();

typedef
void
(*PG_PointersWindowDestroyFunction)(
    void* window
);

typedef
PG_Result
(*PG_PointersWindowConstructFunction)(
    PG_Base* base,
    void* window
);

typedef
void
(*PG_PointersWindowDestructFunction)(
    PG_Base* base,
    void* window
);

typedef
void
(*PG_PointersWindowDrawFunction)(
    PG_Base* base,
    void* window
);

typedef
void
(*PG_PointersWindowSetSizeFunction)(
    PG_Base* base,
    void* window,
    const PG_WindowGeometry window_geometry
);

typedef
void
(*PG_PointersWindowSetTitleFunction)(
    PG_Base* base,
    void* window,
    const PG_C8* title
);

#endif