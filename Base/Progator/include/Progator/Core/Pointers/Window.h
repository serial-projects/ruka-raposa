/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersWindow_h
#define PGCorePointersWindow_h

#include "Progator/Types/Basics.h"
#include "Progator/Core/Base.h"

/** Every Function: */

typedef
void*
(*PG_PointersWindowNewFunction)();

typedef
void
(*PG_PointersWindowFreeFunction)(
    void* window
);

typedef
PG_Result
(*PG_PointersWindowConstructFunction)(
    void* window,
    const PG_Base* base
);

typedef
void
(*PG_PointersWindowDestructFunction)(
    void* window
);

typedef
void
(*PG_PointersWindowDrawFunction)(
    void* window
);

typedef
void
(*PG_PointersWindowSetSizeFunction)(
    void* window,
    const PG_U16 width,
    const PG_U16 height
);

typedef
void
(*PG_PointersWindowSetTitleFunction)(
    void* window,
    const PG_C8* title
);

#endif