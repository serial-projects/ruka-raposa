/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersShader_h
#define PGCorePointersShader_h

#include "Progator/Types/Basics.h"
#include "Progator/Core/Base.h"

typedef
void*
(*PG_PointersShaderNewFunction)();

typedef
void
(*PG_PointersShaderFreeFunction)(
    void* shader
);

typedef
void
(*PG_PointersShaderConstructFunction)(
    void* shader,
    void* renderer
);

typedef
void
(*PG_PointersShaderDestructFunction)(
    void* shader
);

typedef
PG_Result
(*PG_PointersShaderBeginCompilationFunction)(
    void* shader
);

typedef
PG_Result
(*PG_PointersShaderLoadVertexShaderFunction)(
    void* shader,
    const PG_U8* buffer
);

typedef
PG_Result
(*PG_PointersShaderLoadFragmentShaderFunction)(
    void* shader,
    const PG_U8* buffer
);

typedef
PG_Result
(*PG_PointersShaderLoadGeometryShaderFunction)(
    void* shader,
    const PG_U8* buffer
);

typedef
PG_Result
(*PG_PointersShaderFinishCompilationFunction)(
    void* shader
);

typedef
void
(*PG_PointersShaderUseFunction)(
    void* shader
);

typedef
void
(*PG_PointersShaderSetDataFunction)(
    void* shader,
    const PG_U8 slot,
    const void* data,
    const PG_Size data_size
);

#endif