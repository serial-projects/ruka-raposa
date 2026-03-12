/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Shader.h"

PG_Shader* PG_ShaderNew()
{
    PG_Shader* new_shader = (PG_Shader*)(
        NK_AllocatorGet(sizeof(PG_Shader))
    );
    return new_shader;
}

void PG_ShaderDestroy(
    PG_Shader* shader
)
{
    NK_AllocatorFree(shader);
}

void PG_ShaderConstruct(
    PG_Base* base,
    PG_Renderer* renderer,
    PG_Shader* shader
)
{
    shader->renderer = renderer;
    shader->backend_object = 
        shader->
            renderer->
            window->
            pointers->
            shader_new();
    shader->
        renderer->
        window->
        pointers->
        shader_construct(
            shader->
                renderer->
                window->
                base,
            shader->
                renderer->
                backend_object,
            shader->
                backend_object
        );
}

void PG_ShaderDestruct(
    PG_Base* base,
    PG_Shader* shader
)
{
    shader->
        renderer->
        window->
        pointers->
        shader_destruct(
            shader->
                renderer->
                window->
                base,
            shader->
                renderer->
                backend_object,
            shader->
                backend_object
        );
        
    shader->
        renderer->
        window->
        pointers->
        shader_destroy(
            shader->
                backend_object
        );
}

PG_Result PG_ShaderBeginCompilation(
    PG_Base* base,
    PG_Shader* shader
)
{
    shader->
        renderer->
        window->
        pointers->
        shader_begin_compilation(
            shader->
                renderer->
                window->
                base,
            shader->
                renderer->
                backend_object,
            shader->
                backend_object
        );
}

PG_Result PG_ShaderLoadVertexShader(
    PG_Base* base,
    PG_Shader* shader,
    const PG_U8* buffer
)
{
    return
        shader->
            renderer->
            window->
            pointers->
            shader_load_vertex_shader(
                shader->
                    renderer->
                    window->
                    base,
                shader->
                    renderer->
                    backend_object,
                shader->
                    backend_object,
                buffer
            );
}

PG_Result PG_ShaderLoadFragmentShader(
    PG_Base* base,
    PG_Shader* shader,
    const PG_U8* buffer
)
{
    return
        shader->
            renderer->
            window->
            pointers->
            shader_load_fragment_shader(
                shader->
                    renderer->
                    window->
                    base,
                shader->
                    renderer->
                    backend_object,
                shader->
                    backend_object,
                buffer
            );
}

PG_Result PG_ShaderLoadGeometryShader(
    PG_Base* base,
    PG_Shader* shader,
    const PG_U8* buffer
)
{
    return
        shader->
            renderer->
            window->
            pointers->
            shader_load_geometry_shader(
                shader->
                    renderer->
                    window->
                    base,
                shader->
                    renderer->
                    backend_object,
                shader->
                    backend_object,
                buffer
            );
}

PG_Result PG_ShaderFinishCompilation(
    PG_Base* base,
    PG_Shader* shader
)
{
    shader->
        renderer->
        window->
        pointers->
        shader_finish_compilation(
            shader->
                renderer->
                window->
                base,
            shader->
                renderer->
                backend_object,
            shader->
                backend_object
        );
}

void PG_ShaderUse(
    PG_Base* base,
    PG_Shader* shader
)
{
    shader->
        renderer->
        window->
        pointers->
        shader_use(
            shader->
                renderer->
                window->
                base,
            shader->
                renderer->
                backend_object,
            shader->
                backend_object
        );
}

void PG_ShaderSetData(
    PG_Base* base,
    PG_Shader* shader,
    const PG_U8 slot,
    const void* data,
    const PG_Size data_size
)
{
    shader->
        renderer->
        window->
        pointers->
        shader_set_data(
            shader->
                renderer->
                window->
                base,
            shader->
                renderer->
                backend_object,
            shader->
                backend_object,
            slot,
            data,
            data_size
        );
}
