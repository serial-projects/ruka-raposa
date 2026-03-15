/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGCorePointers_h
#define PGCorePointers_h

#include "Progator/Core/Pointers/Window.h"
#include "Progator/Core/Pointers/Renderer.h"
#include "Progator/Core/Pointers/Shader.h"
#include "Progator/Core/Pointers/Mesh.h"
#include "Progator/Core/Pointers/Framebuffer.h"
#include "Progator/Core/Pointers/Texture.h"

/**
 * @brief This is every function an backend must implement, they are essential
 * and map directly to the generic API functions we provide for objects like
 * `PG_Window` and more.
 * 
 * @note All the `PG_PointersWindowNewFunction` always return an `void*` instead
 * of an determined object, this is done because we actually don't know what
 * the backend we are using, we just pass the pointer to the implementation.
 */
typedef struct PG_Pointers
{
    /** Window: */

    PG_PointersWindowNewFunction window_new;
    PG_PointersWindowDestroyFunction window_destroy;
    PG_PointersWindowConstructFunction window_construct;
    PG_PointersWindowDestructFunction window_destruct;
    PG_PointersWindowDrawFunction window_draw;
    PG_PointersWindowSetSizeFunction window_set_size;
    PG_PointersWindowSetTitleFunction window_set_title;

    /** Renderer: */

    PG_PointersRendererNewFunction renderer_new;
    PG_PointersRendererDestroyFunction renderer_destroy;
    PG_PointersRendererConstructFunction renderer_construct;
    PG_PointersRendererDestructFunction renderer_destruct;
    PG_PointersRendererSetViewportFunction renderer_set_viewport;
    PG_PointersRendererDrawFunction renderer_draw;
    PG_PointersRendererClearFunction renderer_clear;
    PG_PointersRendererEnableFeatureFunction renderer_enable_feature;
    PG_PointersRendererDisableFeatureFunction renderer_disable_feature;

    /** Shader: */

    PG_PointersShaderNewFunction shader_new;
    PG_PointersShaderDestroyFunction shader_destroy;
    PG_PointersShaderConstructFunction shader_construct;
    PG_PointersShaderDestructFunction shader_destruct;
    PG_PointersShaderBeginCompilationFunction shader_begin_compilation;
    PG_PointersShaderLoadVertexShaderFunction shader_load_vertex_shader;
    PG_PointersShaderLoadFragmentShaderFunction shader_load_fragment_shader;
    PG_PointersShaderLoadGeometryShaderFunction shader_load_geometry_shader;
    PG_PointersShaderFinishCompilationFunction shader_finish_compilation;
    PG_PointersShaderUseFunction shader_use;
    PG_PointersShaderSetDataFunction shader_set_data;

    /** Mesh: */

    PG_PointersMeshNewFunction mesh_new;
    PG_PointersMeshDestroyFunction mesh_destroy;
    PG_PointersMeshConstructFunction mesh_construct;
    PG_PointersMeshDestructFunction mesh_destruct;
    PG_PointersMeshUseFunction mesh_use;
    PG_PointersMeshSetDataFunction mesh_set_data;
    PG_PointersMeshDrawFunction mesh_draw;

    /** Framebuffer: */
    
    PG_PointersFramebufferNewFunction framebuffer_new;
    PG_PointersFramebufferDestroyFunction framebuffer_destroy;
    PG_PointersFramebufferConstructFunction framebuffer_construct;
    PG_PointersFramebufferDestructFunction framebuffer_destruct;
    PG_PointersFramebufferUseFunction framebuffer_use;
    PG_PointersFramebufferLeaveFunction framebuffer_leave;
    PG_PointersFramebufferBeTextureFunction framebuffer_be_texture;

    /** Texture: */

    PG_PointersTextureNewFunction texture_new;
    PG_PointersTextureDestroyFunction texture_destroy;
    PG_PointersTextureConstructFunction texture_construct;
    PG_PointersTextureDestructFunction texture_destruct;
    PG_PointersTextureUseFunction texture_use;
    PG_PointersTextureSetDataFunction texture_set_data;
} PG_Pointers;

#endif