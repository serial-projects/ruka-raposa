#include "Progator/Backends/OG33.h"

/**
 * @brief Contains the function table for the `PG_Pointers` for OpenGL 33
 * Backend system.
 */
static
PG_Pointers PG_BackendsOG33Implementation = 
{
    /* Window: */
    (PG_PointersWindowNewFunction)(PG_BackendsOG33WindowNew),
    (PG_PointersWindowFreeFunction)(PG_BackendsOG33WindowFree),
    (PG_PointersWindowConstructFunction)(PG_BackendsOG33WindowConstruct),
    (PG_PointersWindowDestructFunction)(PG_BackendsOG33WindowDestruct),
    (PG_PointersWindowDrawFunction)(PG_BackendsOG33WindowDraw),
    (PG_PointersWindowSetSizeFunction)(PG_BackendsOG33WindowSetSize),
    (PG_PointersWindowSetTitleFunction)(PG_BackendsOG33WindowSetTitle),

    /* Renderer: */
    (PG_PointersRendererNewFunction)(PG_BackendsOG33RendererNew),
    (PG_PointersRendererFreeFunction)(PG_BackendsOG33RendererFree),
    (PG_PointersRendererConstructFunction)(PG_BackendsOG33RendererConstruct),
    (PG_PointersRendererDestructFunction)(PG_BackendsOG33RendererDestruct),
    (PG_PointersRendererSetViewportFunction)(PG_BackendsOG33RendererSetViewport),
    (PG_PointersRendererDrawFunction)(PG_BackendsOG33RendererDraw),
    (PG_PointersRendererClearFunction)(PG_BackendsOG33RendererClear),
    (PG_PointersRendererEnableFeatureFunction)(PG_BackendsOG33RendererEnableFeature),
    (PG_PointersRendererDisableFeatureFunction)(PG_BackendsOG33RendererDisableFeature),
    
    /** Shader: */
    (PG_PointersShaderNewFunction)(PG_BackendsOG33ShaderNew),
    (PG_PointersShaderFreeFunction)(PG_BackendsOG33ShaderFree),
    (PG_PointersShaderConstructFunction)(PG_BackendsOG33ShaderConstruct),
    (PG_PointersShaderDestructFunction)(PG_BackendsOG33ShaderDestruct),
    (PG_PointersShaderBeginCompilationFunction)(PG_BackendsOG33ShaderBeginCompilation),
    (PG_PointersShaderLoadVertexShaderFunction)(PG_BackendsOG33ShaderLoadVertexShader),
    (PG_PointersShaderLoadFragmentShaderFunction)(PG_BackendsOG33ShaderLoadFragmentShader),
    (PG_PointersShaderLoadGeometryShaderFunction)(PG_BackendsOG33ShaderLoadGeometryShader),
    (PG_PointersShaderFinishCompilationFunction)(PG_BackendsOG33ShaderFinishCompilation),
    (PG_PointersShaderUseFunction)(PG_BackendsOG33ShaderUse),
    (PG_PointersShaderSetDataFunction)(PG_BackendsOG33ShaderSetData),

    /** Mesh: */
    (PG_PointersMeshNewFunction)(PG_BackendsOG33MeshNew),
    (PG_PointersMeshFreeFunction)(PG_BackendsOG33MeshFree),
    (PG_PointersMeshConstructFunction)(PG_BackendsOG33MeshConstruct),
    (PG_PointersMeshDestructFunction)(PG_BackendsOG33MeshDestruct),
    (PG_PointersMeshUseFunction)(PG_BackendsOG33MeshUse),
    (PG_PointersMeshSetDataFunction)(PG_BackendsOG33MeshSetData),
    (PG_PointersMeshDrawFunction)(PG_BackendsOG33MeshDraw),

    /** Framebuffer: */
    (PG_PointersFramebufferNewFunction)(PG_BackendsOG33FramebufferNew),
    (PG_PointersFramebufferFreeFunction)(PG_BackendsOG33FramebufferFree),
    (PG_PointersFramebufferConstructFunction)(PG_BackendsOG33FramebufferConstruct),
    (PG_PointersFramebufferDestructFunction)(PG_BackendsOG33FramebufferDestruct),
    (PG_PointersFramebufferUseFunction)(PG_BackendsOG33FramebufferUse),
    (PG_PointersFramebufferLeaveFunction)(PG_BackendsOG33FramebufferLeave),
    (PG_PointersFramebufferBeTextureFunction)(PG_BackendsOG33FramebufferBeTexture),

    /** Texture: */
    (PG_PointersTextureNewFunction)(PG_BackendsOG33TextureNew),
    (PG_PointersTextureFreeFunction)(PG_BackendsOG33TextureFree),
    (PG_PointersTextureConstructFunction)(PG_BackendsOG33TextureConstruct),
    (PG_PointersTextureDestructFunction)(PG_BackendsOG33TextureDestruct),
    (PG_PointersTextureUseFunction)(PG_BackendsOG33TextureUse),
    (PG_PointersTextureSetDataFunction)(PG_BackendsOG33TextureSetData)
};

PG_Pointers*
PG_BackendsOG33Get()
{
    return &PG_BackendsOG33Implementation;
}