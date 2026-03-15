/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGObjectsShader_h
#define PGObjectsShader_h

#include "Progator/Core/Base.h"
#include "Progator/Core/Pointers.h"
#include "Progator/Types/Basics.h"
#include "Progator/Objects/Renderer.h"

/**
 * An shader is code that should run on the `GPU` responsible for vertex
 * position, fragment (color) and geometry.
 * 
 * @brief `Shader` program that is used to modify drawing `mesh(es)`
 */
typedef struct PG_Shader
{
    /**
     * @brief Contains the backend object for the `PG_Shader`
     */
    void* backend_object;

    /**
     * @brief Contains the `PG_Renderer` we are currently attached to, it will
     * provide the `PG_Pointers*` for the `PG_Shader` to work with.
     */
    PG_Renderer* renderer;
} PG_Shader;

/**
 * @brief Creates an new `PG_Shader
 */
PG_Shader*
PG_ShaderNew();

/**
 * @brief Frees an `PG_Shader` created by `PG_ShaderNew`
 * 
 * @warning Does not imply on `PG_ShaderConstruct`
 */
void
PG_ShaderDestroy(
    PG_Shader* shader
);

/**
 * @brief Constructs an `PG_Shader` object.
 */
void
PG_ShaderConstruct(
    PG_Base* base,
    PG_Renderer* renderer,
    PG_Shader* shader
);

/**
 * @brief Destructs an `PG_Shader` object.
 */
void
PG_ShaderDestruct(
    PG_Base* base,
    PG_Shader* shader
);

/**
 * @brief Some API(s) might require to heat up the compiler/interpreter for the
 * shaders, so, this function will call the backend to get ready to compile
 * the shaders.
 */
PG_Result
PG_ShaderBeginCompilation(
    PG_Base* base,
    PG_Shader* shader
);

/**
 * @brief Loads an `Vertex Code` into the shader to be compiled.
 */
PG_Result
PG_ShaderLoadVertexShader(
    PG_Base* base,
    PG_Shader* shader,
    const PG_U8* buffer
);

/**
 * @brief Loads an `Fragment Code` into the shader to be compiled.
 */
PG_Result
PG_ShaderLoadFragmentShader(
    PG_Base* base,
    PG_Shader* shader,
    const PG_U8* buffer
);

/**
 * @brief Loads an `Geometry Code` into the shader to be compiled.
 */
PG_Result
PG_ShaderLoadGeometryShader(
    PG_Base* base,
    PG_Shader* shader,
    const PG_U8* buffer
);

/**
 * @brief In case the compiler needs some cleaning or heat up for the linking
 * stage. This function asks the backend to get ready to link and finish the
 * compilation. It *ALSO* should link here the other shaders.
 */
PG_Result
PG_ShaderFinishCompilation(
    PG_Base* base,
    PG_Shader* shader
);

/**
 * @brief Sets the `PG_Shader` to be the current one being used.
 */
void
PG_ShaderUse(
    PG_Base* base,
    PG_Shader* shader
);

/**
 * @brief Sets the `PG_Shader` data. This is an UBO, meaning you need to
 * specify the data you want to send to the shader.
 */
void
PG_ShaderSetData(
    PG_Base* base,
    PG_Shader* shader,
    const PG_U8 slot,
    const void* data,
    const PG_Size data_size
);

#endif
