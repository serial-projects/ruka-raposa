/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGBackendsOG33Types_h
#define PGBackendsOG33Types_h

#include "Progator/Backends/OG33/GL.h"

/**
 * @note We give names to the objects to have an consistency around the
 * OpenGL backend.
 */

/**
 * Texture Objects:
 */

typedef GLuint PG_BackendsOG33Texture2DHandle;
typedef GLuint PG_BackendsOG33Texture3DHandle;

/**
 * Shader Objects:
 */

typedef GLuint PG_BackendsOG33VertexShaderHandle;
typedef GLuint PG_BackendsOG33FragmentShaderHandle;
typedef GLuint PG_BackendsOG33GeometryShaderHandle;
typedef GLuint PG_BackendsOG33ProgramShaderHandle;
typedef GLuint PG_BackendsOG33UniformBufferHandle;
typedef GLuint PG_BackendsOG33VertexBufferHandle;
typedef GLuint PG_BackendsOG33VertexAttributeBufferHandle;

/**
 * Framebuffer Objects:
 */

typedef GLuint PG_BackendsOG33FramebufferHandle;
typedef GLuint PG_BackendsOG33RenderbufferHandle;
typedef GLuint PG_BackendsOG33FramebufferTextureHandle;

#endif