/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersTexture_h
#define PGCorePointersTexture_h

#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Core/Base.h"

typedef
void*
(*PG_PointersTextureNewFunction)();

typedef
void
(*PG_PointersTextureDestroyFunction)(
    void* texture
);

typedef
void
(*PG_PointersTextureConstructFunction)(
    PG_Base* base,
    void* renderer,
    void* texture
);

typedef
void
(*PG_PointersTextureDestructFunction)(
    PG_Base* base,
    void* renderer,
    void* texture
);

typedef
void
(*PG_PointersTextureUseFunction)(
    PG_Base* base,
    void* renderer,
    void* texture,
    const PG_U8 slot
);

typedef
void
(*PG_PointersTextureSetDataFunction)(
    PG_Base* base,
    void* renderer,
    void* texture,
    const void* data,
    const PG_Size data_size,
    const PG_U32 width,
    PG_U32 height
);

#endif