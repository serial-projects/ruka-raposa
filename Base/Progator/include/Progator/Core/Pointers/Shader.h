/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#ifndef PGCorePointersShader_h
#define PGCorePointersShader_h

#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Core/Base.h"

typedef
void*
(*PG_PointersShaderNewFunction)();

typedef
void
(*PG_PointersShaderDestructFunction)(
    void* shader
);

typedef
void
(*PG_PointersShaderConstructFunction)(
    PG_Base* base,
    void* renderer,
    void* shader
);

typedef
void
(*PG_PointersShaderDestructFunction)(
    PG_Base* base,
    void* renderer,
    void* shader
);

typedef
PG_Result
(*PG_PointersShaderBeginCompilationFunction)(
    PG_Base* base,
    void* renderer,
    void* shader
);

typedef
PG_Result
(*PG_PointersShaderLoadVertexShaderFunction)(
    PG_Base* base,
    void* renderer,
    void* shader,
    const PG_U8* buffer
);

typedef
PG_Result
(*PG_PointersShaderLoadFragmentShaderFunction)(
    PG_Base* base,
    void* renderer,
    void* shader,
    const PG_U8* buffer
);

typedef
PG_Result
(*PG_PointersShaderLoadGeometryShaderFunction)(
    PG_Base* base,
    void* renderer,
    void* shader,
    const PG_U8* buffer
);

typedef
PG_Result
(*PG_PointersShaderFinishCompilationFunction)(
    PG_Base* base,
    void* renderer,
    void* shader
);

typedef
void
(*PG_PointersShaderUseFunction)(
    PG_Base* base,
    void* renderer,
    void* shader
);

typedef
void
(*PG_PointersShaderSetDataFunction)(
    PG_Base* base,
    void* renderer,
    void* shader,
    const PG_U8 slot,
    const void* data,
    const PG_Size data_size
);


#endif