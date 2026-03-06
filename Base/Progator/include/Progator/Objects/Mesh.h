/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGObjectsMesh_h
#define PGObjectsMesh_h

#include "Progator/Core/Base.h"
#include "Progator/Core/Pointers.h"
#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Objects/Renderer.h"

typedef struct PG_Mesh
{
    void* backend_object;
    PG_Renderer* renderer;
} PG_Mesh;

PG_Mesh* PG_MeshNew();
void PG_MeshDestroy(PG_Mesh* mesh);
void PG_MeshConstruct(PG_Base* base, PG_Renderer* renderer, PG_Mesh* mesh);
void PG_MeshDestruct(PG_Base* base, PG_Mesh* mesh);
void PG_MeshUse(PG_Base* base, PG_Mesh* mesh);
void PG_MeshSetData(PG_Base* base, PG_Mesh* mesh, const void* data, const PG_Size nverts);
void PG_MeshDraw(PG_Base* base, PG_Mesh* mesh);

#endif
