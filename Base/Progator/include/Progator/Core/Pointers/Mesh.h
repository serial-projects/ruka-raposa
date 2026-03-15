/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersMesh_h
#define PGCorePointersMesh_h

#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Core/Base.h"

typedef
void*
(*PG_PointersMeshNewFunction)();

typedef
void
(*PG_PointersMeshFreeFunction)(
    void* mesh
);

typedef
void
(*PG_PointersMeshConstructFunction)(
    PG_Base* base,
    void* renderer,
    void* mesh
);

typedef
void
(*PG_PointersMeshDestructFunction)(
    PG_Base* base,
    void* renderer,
    void* mesh
);

typedef
void
(*PG_PointersMeshUseFunction)(
    PG_Base* base,
    void* renderer,
    void* mesh
);

typedef
void
(*PG_PointersMeshSetDataFunction)(
    PG_Base* base,
    void* renderer,
    void* mesh,
    const void* data,
    const PG_Size nverts
);

typedef
void
(*PG_PointersMeshDrawFunction)(
    PG_Base* base,
    void* renderer,
    void* mesh
);

#endif