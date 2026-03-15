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
#include "Progator/Objects/Renderer.h"

/**
 * An mesh for `Progator` is described as an object that holds an bunch of
 * points that can become triangles, those are stored in a `buffer` that may
 * or not be on the `GPU`. There can only be *ONE* mesh per time to be
 * rendered and `Draw` must the target for it.
 * 
 * @brief Object to hold 3D object.
 */
typedef struct PG_Mesh
{
    /**
     * @brief Contains the backend object for the `PG_Mesh`
     */
    void* backend_object;

    /**
     * @brief Contains the `PG_Renderer` we are currently attached to, it will
     * provide the `PG_Pointers*` for the `PG_Mesh` to work with.
     */
    PG_Renderer* renderer;
} PG_Mesh;

/**
 * @brief Creates an new `PG_Mesh`
 * 
 * @warning Does not imply on `PG_MeshConstruct`
 */
PG_Mesh*
PG_MeshNew();

/**
 * @brief Frees an `PG_Mesh` created by `PG_MeshNew`
 */
void
PG_MeshDestroy(
    PG_Mesh* mesh
);

/**
 * @brief Construct an new `PG_Mesh`
 * 
 * @warning Implies on `PG_MeshUse` since this function will construct an `mesh`
 * object. So, if you were working with another object, either you had to save
 * it before constructing an mesh or forget it.
 */
void
PG_MeshConstruct(
    PG_Base* base,
    PG_Renderer* renderer,
    PG_Mesh* mesh
);

/**
 * @brief Destructs an `PG_Mesh`
 * 
 * @warning Like `PG_MeshConstruct`, this function implies on `PG_MeshUse`.
 */
void
PG_MeshDestruct(
    PG_Base* base,
    PG_Mesh* mesh
);

/**
 * Sets the mesh to be the current one rendering, we use `context` to
 * order what we are working with, this is from `OpenGL` and since `Progator`
 * was originally written for `OpenGL` this pattern should be replicated with
 * some tweaks to `Vulkan` and other rendering APIs. When `Use` is called, the
 * mesh will become the one to be acted upon.
 * 
 * @brief Set the `PG_Mesh` to be the current one we are working with.
 */
void
PG_MeshUse(
    PG_Base* base,
    PG_Mesh* mesh
);

/**
 * @brief Copies the data from the `data` buffer to the `buffer` we will be
 * storing the mesh content/points.
 * 
 * @warning By default, `Progator` only accepts the buffer to be on the:
 * Vertex, UV and Normal Order, anything else will result in a unaligned
 * buffer, this is for *ALL* apis, from `Vulkan` to `OpenGL`.
 * 
 * @warning This does not imply on `PG_MeshUse`, you should call `PG_MeshUse`
 * before using this function in case you want to change the buffer.
 */
void
PG_MeshSetData(
    PG_Base* base,
    PG_Mesh* mesh,
    const void* data,
    const PG_Size nverts
);

/**
 * @brief Creates an request for the mesh to be drawn on the `PG_Framebuffer`
 * that is currently being used by `PG_Renderer`.
 * 
 * @warning This does not imply on `PG_MeshUse`, you should call `PG_MeshUse`
 * before using this function in case you want to change the buffer.
 */
void
PG_MeshDraw(
    PG_Base* base,
    PG_Mesh* mesh
);

#endif
