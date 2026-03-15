/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Backends/OG33/Mesh.h"

PG_BackendsOG33Mesh*
PG_BackendsOG33MeshNew()
{
    PG_BackendsOG33Mesh* new_mesh = 
        (PG_BackendsOG33Mesh*)(
            NK_AllocatorGet(sizeof(PG_BackendsOG33Mesh))
        );
    return new_mesh;
}

void
PG_BackendsOG33MeshDestroy(
    PG_BackendsOG33Mesh* mesh
)
{
    NK_AllocatorFree(mesh);
}

void
PG_BackendsOG33MeshConstruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Mesh* mesh
)
{
    glGenBuffers(1, &mesh->VBO);
    glGenVertexArrays(1, &mesh->VAO);
    mesh->nverts = 0;
}

void
PG_BackendsOG33MeshDestruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Mesh* mesh
)
{
    if(mesh->VBO == 0)
    {
        glDeleteBuffers(1, &mesh->VBO);
    }

    if(mesh->VAO == 0)
    {
        glDeleteVertexArrays(1, &mesh->VAO);
    }

    mesh->nverts = 0;
}

void
PG_BackendsOG33MeshUse(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Mesh* mesh
)
{
    glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO);
    glBindVertexArray(mesh->VAO);
}

void
PG_BackendsOG33MeshSetData(
    PG_Base* base, 
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Mesh* mesh,
    const void* data,
    const PG_Size nverts
)
{
    /** TODO: When drawing the mesh, it is simple to just / sizeof(PG_F32) */
    mesh->nverts = nverts;
    glBufferData(
        GL_ARRAY_BUFFER,
        nverts * sizeof(PG_F32),
        data,
        GL_STATIC_DRAW
    );

    /**
     * NOTE: Here we follow Progator's specification: 3 pos/ 2 uv/ 3 normals:
     * This is not possible to change and is done to make sure every single
     * backend is as consistent as possible.
     */
    #define _S (3 + 2 + 3) * sizeof(PG_F32)
    #define _A(a_, b_, c_)                      \
        glVertexAttribPointer(                  \
            a_,                                 \
            b_,                                 \
            GL_FLOAT,                           \
            GL_FALSE,                           \
            _S,                                 \
            (void*)((0 + c_) * sizeof(PG_F32))  \
        )
        _A(0, 3, 0);
        _A(1, 2, 3);
        _A(2, 3, 3 + 2);
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);
    #undef _A
    #undef _S
}

void
PG_BackendsOG33MeshDraw(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Mesh* mesh
)
{
    glDrawArrays(
        GL_TRIANGLES,
        0,
        mesh->nverts
    );
}