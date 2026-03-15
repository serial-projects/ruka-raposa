/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGBackendsOG33Mesh_h
#define PGBackendsOG33Mesh_h

#include "Progator/Backends/OG33/Config.h"
#include "Progator/Backends/OG33/GL.h"
#include "Progator/Backends/OG33/Types.h"
#include "Progator/Backends/OG33/Renderer.h"
#include "Progator/Core/Base.h"

typedef struct PG_BackendsOG33Mesh
{
    /** The two main buffers we need to draw: */
    PG_BackendsOG33VertexBufferHandle VBO;
    PG_BackendsOG33VertexAttributeBufferHandle VAO;

    /**
     * Keep a counter of how much triangles we need to draw:
     * 
     * NOTE: By Progator Specification, we can ONLY draw triangles, meaning 
     * quads will be bugged, so always say how much data you have for triangles,
     * why? Because most drivers break down QUADS to Triangles.
     */
    PG_Size nverts;
} PG_BackendsOG33Mesh;

PG_BackendsOG33Mesh*
PG_BackendsOG33MeshNew();

void
PG_BackendsOG33MeshFree(
    PG_BackendsOG33Mesh* mesh
);

void
PG_BackendsOG33MeshConstruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Mesh* mesh
);

void
PG_BackendsOG33MeshDestruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Mesh* mesh
);

void
PG_BackendsOG33MeshUse(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Mesh* mesh
);

void
PG_BackendsOG33MeshSetData(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Mesh* mesh,
    const void* data,
    const PG_Size nverts
);

void
PG_BackendsOG33MeshDraw(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Mesh* mesh
);

#endif