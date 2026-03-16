/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersTexture_h
#define PGCorePointersTexture_h

#include "Progator/Types/Basics.h"
#include "Progator/Core/Base.h"

typedef
void*
(*PG_PointersTextureNewFunction)();

typedef
void
(*PG_PointersTextureFreeFunction)(
    void* texture
);

typedef
void
(*PG_PointersTextureConstructFunction)(
    void* texture,
    void* renderer
);

typedef
void
(*PG_PointersTextureDestructFunction)(
    void* texture
);

typedef
void
(*PG_PointersTextureUseFunction)(
    void* texture,
    const PG_U8 slot
);

typedef
void
(*PG_PointersTextureSetDataFunction)(
    void* texture,
    const void* data,
    const PG_Size data_size,
    const PG_U32 width,
    PG_U32 height
);

#endif