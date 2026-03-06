/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Backends/OG33/Shader.h"

PG_BackendsOG33Shader* PG_BackendsOG33ShaderNew()
{
    PG_BackendsOG33Shader* new_shader = 
        (PG_BackendsOG33Shader*)(NK_malloc(sizeof(PG_BackendsOG33Shader)));
    return new_shader;
}

void PG_BackendsOG33ShaderDestroy(
    PG_BackendsOG33Shader* shader
)
{
    NK_free(shader);
}

void PG_BackendsOG33ShaderConstruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader
)
{
    /** 
     * NOTE: We don't construct the shaders and neither the UBO's, we do this
     * at the runtime to avoid creating useless elements, but we do clean the
     * memory to make sure it is clean.
     */
    NK_memset(
        (void*)(&shader->UBO_pool),
        0,
        (
            sizeof(PG_BackendsOG33UniformBufferHandle) *
            PG_CONFIG_BACKENDS_OG33_MAX_SHADER_DATA_SLOTS
        )
    );

    /**
     * VS = Vertex Shader
     * FS = Fragment Shader
     * GS = Geometry Shader
     * SP = Shader Program
     */
    shader->VS = 0;
    shader->FS = 0;
    shader->GS = 0;
    shader->SP = 0;
}

void PG_BackendsOG33ShaderDestruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader
)
{
    for(
        PG_U8 index = 0;
        index < PG_CONFIG_BACKENDS_OG33_MAX_SHADER_DATA_SLOTS;
        index++
    )
    {
        if(shader->UBO_pool[index] == 0)
        {
            glDeleteBuffers(1, &shader->UBO_pool[index]);
        }
    }

    /** Delete the shader: */
    #define _A(shader) \
        if(shader != 0) { glDeleteShader(shader); }
    _A(shader->VS);
    _A(shader->FS);
    _A(shader->GS);
    #undef _A

    /** Delete the program: */
    glDeleteProgram(shader->SP);
}

PG_Result PG_BackendsOG33ShaderBeginCompilation(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader
)
{
    /**
     * NOTE: We don't need to do anything to prepare OpenGL to shader
     * compilation, for example, if we had an libncurses, we could prepare the
     * compiler on this stage (imagining an whole compiler around here).
     * 
     * This is most kept to keep an extra layer of support to LoadXXXShader()
     * functions.
     */
    return true;
}

PG_Result PG_BackendsOG33ShaderLoadVertexShader(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader,
    const PG_U8* buffer
)
{
    /** NOTE: We do the whole steps to compiling shaders: */
    shader->VS = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* b = (const GLchar*)buffer;
    glShaderSource(shader->VS, 1, &b, NULL);
    glCompileShader(shader->VS);

    GLint adquired_status;
    glGetShaderiv(shader->VS, GL_COMPILE_STATUS, &adquired_status);
    if(adquired_status == GL_FALSE)
    {
        PG_C8 log_buffer[PG_CONFIG_BACKENDS_OG33_SHADER_LOG_SIZE];
        glGetShaderInfoLog(
            shader->VS,
            PG_CONFIG_BACKENDS_OG33_SHADER_LOG_SIZE,
            NULL,
            (GLchar*)(&log_buffer)
        );

        NK_ValidatorWarning(
            base->attached_validator,
            "[Progator/ OG33 Backend Shader]: Failed to compile VS, reason: \"%s\"",
            log_buffer
        );

        return false;
    }

    return true;
}

PG_Result PG_BackendsOG33ShaderLoadFragmentShader(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader,
    const PG_U8* buffer
)
{
    /** NOTE: We do the whole steps to compiling shaders: */
    shader->FS = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar* b = (const GLchar*)buffer;
    glShaderSource(shader->FS, 1, &b, NULL);
    glCompileShader(shader->FS);

    GLint adquired_status;
    glGetShaderiv(shader->FS, GL_COMPILE_STATUS, &adquired_status);
    if(adquired_status == GL_FALSE)
    {
        PG_C8 log_buffer[PG_CONFIG_BACKENDS_OG33_SHADER_LOG_SIZE];
        glGetShaderInfoLog(
            shader->FS,
            PG_CONFIG_BACKENDS_OG33_SHADER_LOG_SIZE,
            NULL,
            (GLchar*)(&log_buffer)
        );

        NK_ValidatorWarning(
            base->attached_validator,
            "[Progator/ OG33 Backend Shader]: Failed to compile FS, reason: \"%s\"",
            log_buffer
        );

        return false;
    }

    return true;
}

PG_Result PG_BackendsOG33ShaderLoadGeometryShader(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader,
    const PG_U8* buffer
)
{
    /** NOTE: We do the whole steps to compiling shaders: */
    shader->GS = glCreateShader(GL_GEOMETRY_SHADER);
    const GLchar* b = (const GLchar*)buffer;
    glShaderSource(shader->GS, 1, &b, NULL);
    glCompileShader(shader->GS);

    GLint adquired_status;
    glGetShaderiv(shader->GS, GL_COMPILE_STATUS, &adquired_status);
    if(adquired_status == GL_FALSE)
    {
        PG_C8 log_buffer[PG_CONFIG_BACKENDS_OG33_SHADER_LOG_SIZE];
        glGetShaderInfoLog(
            shader->GS,
            PG_CONFIG_BACKENDS_OG33_SHADER_LOG_SIZE,
            NULL,
            (GLchar*)(&log_buffer)
        );

        NK_ValidatorWarning(
            base->attached_validator,
            "[Progator/ OG33 Backend Shader]: Failed to compile GS, reason: \"%s\"",
            log_buffer
        );

        return false;
    }

    return true;
}

PG_Result PG_BackendsOG33ShaderFinishCompilation(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader
)
{
    shader->SP = glCreateProgram();
    #define _A(shader_) \
        if(shader_ != 0) { glAttachShader(shader->SP, shader_); }
    _A(shader->VS);
    _A(shader->FS);
    _A(shader->GS);
    #undef _A
    
    /** Link: */
    glLinkProgram(shader->SP);

    /** Check the status: */
    GLint linkage_status;
    glGetProgramiv(shader->SP, GL_LINK_STATUS, &linkage_status);
    if(linkage_status == GL_FALSE)
    {
        PG_C8 log_buffer[PG_CONFIG_BACKENDS_OG33_SHADER_LOG_SIZE];
        glGetProgramInfoLog(
            shader->SP,
            PG_CONFIG_BACKENDS_OG33_SHADER_LOG_SIZE,
            NULL,
            (GLchar*)(&log_buffer)
        );

        NK_ValidatorWarning(
            base->attached_validator,
            "[Progator/ OG33 Backend Shader]: Failed to link shaders, reason: \"%s\"",
            log_buffer
        );

        return false;
    }

    return true;
}

void PG_BackendsOG33ShaderUse(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader
)
{
    glUseProgram(shader->SP);
}

void PG_BackendsOG33ShaderSetData(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Shader* shader,
    const PG_U8 slot,
    const void* data,
    const PG_Size data_size
)
{
    /** Are we within the range? */
    if(slot >= PG_CONFIG_BACKENDS_OG33_MAX_SHADER_DATA_SLOTS)
    {
        NK_ValidatorWarning(
            base->attached_validator,
            "[Progator/ OG33 Backend Shader]: Failed to copy data to slot %d (max: %d)",
            (PG_S32)(slot),
            (PG_S32)(PG_CONFIG_BACKENDS_OG33_MAX_SHADER_DATA_SLOTS)
        );
        return;
    }

    /** We get the current using handle: */
    PG_BackendsOG33UniformBufferHandle* using_handle = &shader->UBO_pool[slot];

    /** No UBO? Then create one: */
    if(*using_handle == 0)
    {
        /** Generate an buffer: */
        glGenBuffers(1, using_handle);

        /** We make sure there is space for our data: */
        glBindBuffer(GL_UNIFORM_BUFFER, *using_handle);
        glBufferData(GL_UNIFORM_BUFFER, data_size, NULL, GL_DYNAMIC_DRAW);
    }
    else
    {
        glBindBuffer(GL_UNIFORM_BUFFER, *using_handle);
    }
    
    /** 
     * NOTE: We could use this, but since the GPU already knows better, we
     * don't need actually, think about this, do you think NV is dumb to
     * let an GL_DYNAMIC_DRAW out there to be switched all the times? We don't
     * need to switch the pointers.
     */
    
    /** glBufferData(GL_UNIFORM_BUFFER, data_size, NULL, GL_DYNAMIC_DRAW); */

    /** Copy the data to the buffer, we don't need anything much here: */
    glBufferSubData(GL_UNIFORM_BUFFER, 0, data_size, data);
    
    /** We say the slot/binding point we want is the slot: */
    glBindBufferBase(GL_UNIFORM_BUFFER, slot, *using_handle);
}

