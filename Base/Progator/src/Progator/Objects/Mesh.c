/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Mesh.h"

PG_Mesh* PG_MeshNew()
{
    PG_Mesh* new_mesh =
        (PG_Mesh*)(NK_malloc(sizeof(PG_Mesh)));
    return new_mesh;
}

void PG_MeshDestroy(
    PG_Mesh* mesh
)
{
    NK_free(mesh);
}

void PG_MeshConstruct(
    PG_Base* base,
    PG_Renderer* renderer,
    PG_Mesh* mesh
)
{
    mesh->renderer = renderer;
    mesh->backend_object = 
        mesh->
            renderer->
            window->
            pointers->
            mesh_new();
    mesh->
        renderer->
        window->
        pointers->
        mesh_construct(
            mesh-> 
                renderer->
                window->
                base,
            mesh->
                renderer->
                backend_object,
            mesh->backend_object
        );
}

void PG_MeshDestruct(
    PG_Base* base,
    PG_Mesh* mesh
)
{
    mesh->
        renderer->
        window->
        pointers->
        mesh_construct(
            mesh-> 
                renderer->
                window->
                base,
            mesh->
                renderer->
                backend_object,
            mesh->backend_object
        );

    mesh->
        renderer->
        window->
        pointers->
        mesh_destroy(
            mesh->
                backend_object
        );
}

void PG_MeshUse(
    PG_Base* base,
    PG_Mesh* mesh
)
{
    mesh->
        renderer->
        window->
        pointers->
        mesh_use(
            mesh-> 
                renderer->
                window->
                base,
            mesh->
                renderer->
                backend_object,
            mesh->backend_object
        );
}

void PG_MeshSetData(
    PG_Base* base,
    PG_Mesh* mesh,
    const void* data,
    const PG_Size nverts
)
{
    mesh->
        renderer->
        window->
        pointers->
        mesh_set_data(
            mesh-> 
                renderer->
                window->
                base,
            mesh->
                renderer->
                backend_object,
            mesh->backend_object,
            data,
            nverts
        );
}

void PG_MeshDraw(
    PG_Base* base,
    PG_Mesh* mesh
)
{
    mesh->
        renderer->
        window->
        pointers->
        mesh_draw(
            mesh-> 
                renderer->
                window->
                base,
            mesh->
                renderer->
                backend_object,
            mesh->backend_object
        );
}