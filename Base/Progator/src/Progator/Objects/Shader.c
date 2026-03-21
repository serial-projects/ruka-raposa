/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Shader.h"

PG_Shader*
PG_ShaderNew()
{
    PG_Shader* new_shader = 
        (PG_Shader*)(
            NK_AllocatorGet(sizeof(PG_Shader))
        );
    return new_shader;
}

void
PG_ShaderFree(
    PG_Shader* shader
)
{
    NK_AllocatorFree(shader);
}

void
PG_ShaderConstruct(
    PG_Shader* shader,
    PG_Renderer* renderer
)
{
    shader->renderer = renderer;
    shader->backend_object = shader->renderer->pointers->shader_new();
    shader->renderer->pointers->shader_construct(
        shader->backend_object,
        shader->renderer->backend_object
    );
}

void
PG_ShaderDestruct(
    PG_Shader* shader
)
{
    shader->renderer->pointers->shader_destruct(
        shader->backend_object
    );
    shader->renderer->pointers->shader_free(
        shader->backend_object
    );
}

PG_Result
PG_ShaderBeginCompilation(
    PG_Shader* shader
)
{
    shader->renderer->pointers->shader_begin_compilation(
        shader->backend_object
    );
}

PG_Result
PG_ShaderLoadVertexShader(
    PG_Shader* shader,
    const PG_U8* buffer
)
{
    return (
        shader->renderer->pointers->shader_load_vertex_shader(
            shader->backend_object,
            buffer
        )
    );
}

PG_Result
PG_ShaderLoadFragmentShader(
    PG_Shader* shader,
    const PG_U8* buffer
)
{
    return (
        shader->renderer->pointers->shader_load_fragment_shader(
            shader->backend_object,
            buffer
        )
    );
}

PG_Result
PG_ShaderLoadGeometryShader(
    PG_Shader* shader,
    const PG_U8* buffer
)
{
    return (
        shader->renderer->pointers->shader_load_geometry_shader(
            shader->backend_object,
            buffer
        )
    );
}

PG_Result
PG_ShaderFinishCompilation(
    PG_Shader* shader
)
{
    return (
        shader->renderer->pointers->shader_finish_compilation(
            shader->backend_object
        )
    );
}

void
PG_ShaderUse(
    PG_Shader* shader
)
{
    shader->renderer->pointers->shader_use(
        shader->backend_object
    );
}

void
PG_ShaderSetData(
    PG_Shader* shader,
    const PG_U8 slot,
    const void* data,
    const PG_Size data_size
)
{
    shader->renderer->pointers->shader_set_data(
        shader->backend_object,
        slot,
        data,
        data_size
    );
}
