/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Mesh.h"

PG_Mesh*
PG_MeshNew()
{
    PG_Mesh* new_mesh =
        (PG_Mesh*)(
            NK_AllocatorGet(sizeof(PG_Mesh))
        );
    return new_mesh;
}

void
PG_MeshFree(
    PG_Mesh* mesh
)
{
    NK_AllocatorFree(mesh);
}

void
PG_MeshConstruct(
    PG_Mesh* mesh,
    PG_Renderer* renderer
)
{
    mesh->renderer = renderer;
    mesh->backend_object = 
        mesh->renderer->pointers->mesh_new();
    mesh->renderer->pointers->mesh_construct(
        mesh->backend_object,
        mesh->renderer->backend_object
    );
}

void
PG_MeshDestruct(
    PG_Mesh* mesh
)
{
    mesh->renderer->pointers->mesh_destruct(
        mesh->backend_object
    );
}

void
PG_MeshUse(
    PG_Mesh* mesh
)
{
    mesh->renderer->pointers->mesh_use(
        mesh->backend_object
    );
}

void
PG_MeshSetData(
    PG_Mesh* mesh,
    const void* data,
    const PG_Size nverts
)
{
    mesh->renderer->pointers->mesh_set_data(
        mesh->backend_object,
        data,
        nverts
    );
}

void
PG_MeshDraw(
    PG_Mesh* mesh
)
{
    mesh->renderer->pointers->mesh_draw(
        mesh->backend_object
    );
}