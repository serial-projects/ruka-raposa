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
    /**
     * @brief Holds an reference to the renderer.
     */
    PG_BackendsOG33Renderer* renderer;

    /**
     * @brief VBO = Vertex Buffer Object.
     */
    PG_BackendsOG33VertexBufferHandle VBO;

    /**
     * @brief VAO = Vertex Attribute Object.
     */
    PG_BackendsOG33VertexAttributeBufferHandle VAO;

    /**
     * @brief How many triangles we can draw.
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
    PG_BackendsOG33Mesh* mesh,
    PG_BackendsOG33Renderer* renderer
);

void
PG_BackendsOG33MeshDestruct(
    PG_BackendsOG33Mesh* mesh
);

void
PG_BackendsOG33MeshUse(
    PG_BackendsOG33Mesh* mesh
);

void
PG_BackendsOG33MeshSetData(
    PG_BackendsOG33Mesh* mesh,
    const void* data,
    const PG_Size nverts
);

void
PG_BackendsOG33MeshDraw(
    PG_BackendsOG33Mesh* mesh
);

#endif