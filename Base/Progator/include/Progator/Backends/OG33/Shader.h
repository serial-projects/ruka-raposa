/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGBackendsOG33Shader_h
#define PGBackendsOG33Shader_h

#include "Progator/Backends/OG33/Config.h"
#include "Progator/Backends/OG33/GL.h"
#include "Progator/Backends/OG33/Types.h"
#include "Progator/Backends/OG33/Renderer.h"
#include "Progator/Core/Base.h"

typedef struct PG_BackendsOG33Shader
{
    /** 
     * @brief VS = Vertex Shader.
     */
    PG_BackendsOG33VertexShaderHandle VS;

    /**
     * @brief FS = Fragment Shader.
     */
    PG_BackendsOG33FragmentShaderHandle FS;

    /**
     * @brief GS = Geometry Shader
     */
    PG_BackendsOG33GeometryShaderHandle GS;

    /**
     * @brief SP = Shader Program.
     */
    PG_BackendsOG33ProgramShaderHandle SP;

    /**
     * @brief In OpenGL, we need to keep our UBO pool around to point to the
     * data slices in the memory.
     */
    PG_BackendsOG33UniformBufferHandle
        UBO_pool[PG_CONFIG_BACKENDS_OG33_MAX_SHADER_DATA_SLOTS];
} PG_BackendsOG33Shader;

PG_BackendsOG33Shader*
PG_BackendsOG33ShaderNew();

void
PG_BackendsOG33ShaderDestruct(
    PG_BackendsOG33Shader* shader
);

void
PG_BackendsOG33ShaderConstruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader
);

void
PG_BackendsOG33ShaderDestruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader
);

PG_Result
PG_BackendsOG33ShaderBeginCompilation(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader
);

PG_Result
PG_BackendsOG33ShaderLoadVertexShader(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader,
    const PG_U8* buffer
);

PG_Result
PG_BackendsOG33ShaderLoadFragmentShader(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader,
    const PG_U8* buffer
);

PG_Result
PG_BackendsOG33ShaderLoadGeometryShader(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader,
    const PG_U8* buffer
);

PG_Result
PG_BackendsOG33ShaderFinishCompilation(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader
);

void
PG_BackendsOG33ShaderUse(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader
);

void
PG_BackendsOG33ShaderSetData(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader,
    const PG_U8 slot,
    const void* data,
    const PG_Size data_size
);

#endif