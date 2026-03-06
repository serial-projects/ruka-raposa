/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGCorePointers_h
#define PGCorePointers_h

#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Core/Base.h"

/** Every Function: */
typedef void*(*PG_PointersWindowNew)();
typedef void(*PG_PointersWindowDestroy)(void* window);
typedef PG_Result(*PG_PointersWindowConstruct)(PG_Base* base, void* window);
typedef void(*PG_PointersWindowDestruct)(PG_Base* base, void* window);
typedef void(*PG_PointersWindowDraw)(PG_Base* base, void* window);
typedef void(*PG_PointersWindowSetSize)(PG_Base* base, void* window, const PG_WindowGeometry window_geometry);
typedef void(*PG_PointersWindowSetTitle)(PG_Base* base, void* window, const PG_C8* title);

typedef void*(*PG_PointersRendererNew)();
typedef void(*PG_PointersRendererDestroy)(void* window);
typedef PG_Result(*PG_PointersRendererConstruct)(PG_Base* base, void* window, void* renderer);
typedef void(*PG_PointersRendererDestruct)(PG_Base* base, void* window, void* renderer);
typedef void(*PG_PointersRendererSetViewport)(PG_Base* base, void* renderer, const PG_ViewportGeometry viewport_geometry);
typedef void(*PG_PointersRendererDraw)(PG_Base* base, void* renderer);
typedef void(*PG_PointersRendererClear)(PG_Base* base, void* renderer, const PG_U32 rgba_color);
typedef void(*PG_PointersRendererEnableFeature)(PG_Base* base, void* renderer, const PG_U8 feature);
typedef void(*PG_PointersRendererDisableFeature)(PG_Base* base, void* renderer, const PG_U8 feature);

typedef void*(*PG_PointersShaderNew)();
typedef void(*PG_PointersShaderDestroy)(void* shader);
typedef void(*PG_PointersShaderConstruct)(PG_Base* base, void* renderer, void* shader);
typedef void(*PG_PointersShaderDestruct)(PG_Base* base, void* renderer, void* shader);
typedef PG_Result(*PG_PointersShaderBeginCompilation)(PG_Base* base, void* renderer, void* shader);
typedef PG_Result(*PG_PointersShaderLoadVertexShader)(PG_Base* base, void* renderer, void* shader, const PG_U8* buffer);
typedef PG_Result(*PG_PointersShaderLoadFragmentShader)(PG_Base* base, void* renderer, void* shader, const PG_U8* buffer);
typedef PG_Result(*PG_PointersShaderLoadGeometryShader)(PG_Base* base, void* renderer, void* shader, const PG_U8* buffer);
typedef PG_Result(*PG_PointersShaderFinishCompilation)(PG_Base* base, void* renderer, void* shader);
typedef void(*PG_PointersShaderUse)(PG_Base* base, void* renderer, void* shader);
typedef void(*PG_PointersShaderSetData)(PG_Base* base, void* renderer, void* shader, const PG_U8 slot, const void* data, const PG_Size data_size);

typedef void*(*PG_PointersMeshNew)();
typedef void(*PG_PointersMeshDestroy)(void* mesh);
typedef void(*PG_PointersMeshConstruct)(PG_Base* base, void* renderer, void* mesh);
typedef void(*PG_PointersMeshDestruct)(PG_Base* base, void* renderer, void* mesh);
typedef void(*PG_PointersMeshUse)(PG_Base* base, void* renderer, void* mesh);
typedef void(*PG_PointersMeshSetData)(PG_Base* base, void* renderer, void* mesh, const void* data, const PG_Size nverts);
typedef void(*PG_PointersMeshDraw)(PG_Base* base, void* renderer, void* mesh);

typedef void*(*PG_PointersFramebufferNew)();
typedef void(*PG_PointersFramebufferDestroy)(void* mesh);
typedef PG_Result(*PG_PointersFramebufferConstruct)(PG_Base* base, void* renderer, void* framebuffer, const PG_ViewportGeometry viewport_geometry);
typedef void(*PG_PointersFramebufferDestruct)(PG_Base* base, void* renderer, void* framebuffer);
typedef void(*PG_PointersFramebufferUse)(PG_Base* base, void* renderer, void* framebuffer);
typedef void(*PG_PointersFramebufferLeave)(PG_Base* base, void* renderer, void* framebuffer);
typedef void(*PG_PointersFramebufferBeTexture)(PG_Base* base, void* renderer, void* framebuffer, const PG_U8 slot);

typedef void*(*PG_PointersTextureNew)();
typedef void(*PG_PointersTextureDestroy)(void* texture);
typedef void(*PG_PointersTextureConstruct)(PG_Base* base, void* renderer, void* texture);
typedef void(*PG_PointersTextureDestruct)(PG_Base* base, void* renderer, void* texture);
typedef void(*PG_PointersTextureUse)(PG_Base* base, void* renderer, void* texture, const PG_U8 slot);
typedef void(*PG_PointersTextureSetData)(PG_Base* base, void* renderer, void* texture, const void* data, const PG_Size data_size, const PG_U32 width, PG_U32 height);

/**
 * \brief This is what every backend must implement:
 */
typedef struct PG_Pointers
{

    /** Window: */
    PG_PointersWindowNew window_new;
    PG_PointersWindowDestroy window_destroy;
    PG_PointersWindowConstruct window_construct;
    PG_PointersWindowDestruct window_destruct;
    PG_PointersWindowDraw window_draw;
    PG_PointersWindowSetSize window_set_size;
    PG_PointersWindowSetTitle window_set_title;

    /** Renderer: */
    PG_PointersRendererNew renderer_new;
    PG_PointersRendererDestroy renderer_destroy;
    PG_PointersRendererConstruct renderer_construct;
    PG_PointersRendererDestruct renderer_destruct;
    PG_PointersRendererSetViewport renderer_set_viewport;
    PG_PointersRendererDraw renderer_draw;
    PG_PointersRendererClear renderer_clear;
    PG_PointersRendererEnableFeature renderer_enable_feature;
    PG_PointersRendererDisableFeature renderer_disable_feature;

    /** Shader: */
    PG_PointersShaderNew shader_new;
    PG_PointersShaderDestroy shader_destroy;
    PG_PointersShaderConstruct shader_construct;
    PG_PointersShaderDestruct shader_destruct;
    PG_PointersShaderBeginCompilation shader_begin_compilation;
    PG_PointersShaderLoadVertexShader shader_load_vertex_shader;
    PG_PointersShaderLoadFragmentShader shader_load_fragment_shader;
    PG_PointersShaderLoadGeometryShader shader_load_geometry_shader;
    PG_PointersShaderFinishCompilation shader_finish_compilation;
    PG_PointersShaderUse shader_use;
    PG_PointersShaderSetData shader_set_data;

    /** Mesh: */
    PG_PointersMeshNew mesh_new;
    PG_PointersMeshDestroy mesh_destroy;
    PG_PointersMeshConstruct mesh_construct;
    PG_PointersMeshDestruct mesh_destruct;
    PG_PointersMeshUse mesh_use;
    PG_PointersMeshSetData mesh_set_data;
    PG_PointersMeshDraw mesh_draw;

    /** Framebuffer: */
    PG_PointersFramebufferNew framebuffer_new;
    PG_PointersFramebufferDestroy framebuffer_destroy;
    PG_PointersFramebufferConstruct framebuffer_construct;
    PG_PointersFramebufferDestruct framebuffer_destruct;
    PG_PointersFramebufferUse framebuffer_use;
    PG_PointersFramebufferLeave framebuffer_leave;
    PG_PointersFramebufferBeTexture framebuffer_be_texture;

    /** Texture: */
    PG_PointersTextureNew texture_new;
    PG_PointersTextureDestroy texture_destroy;
    PG_PointersTextureConstruct texture_construct;
    PG_PointersTextureDestruct texture_destruct;
    PG_PointersTextureUse texture_use;
    PG_PointersTextureSetData texture_set_data;
} PG_Pointers;

#endif