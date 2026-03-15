/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGObjectsFramebuffer_h
#define PGObjectsFramebuffer_h

#include "Progator/Core/Base.h"
#include "Progator/Core/Pointers.h"
#include "Progator/Types/Basics.h"
#include "Progator/Objects/Renderer.h"

/**
 * For Progator, an `PG_Framebuffer` is a object were we can draw 
 * instead of the default framebuffer, we can only select *ONE* at time and
 * we can `Use` or `Leave`, this `PG_Framebuffer` can have the capacity of
 * acting like a texture.
 * 
 * @brief `Framebuffer` or `Canvas` object.
 */
typedef struct PG_Framebuffer
{
    /**
     * @brief Contains the backend object for the `PG_Framebuffer`
     */
    void* backend_object;

    /**
     * @brief Contains the `PG_Renderer` we are currently attached to, it will
     * provide the `PG_Pointers*` for the `PG_Framebuffer` to work with.
     */
    PG_Renderer* renderer;
} PG_Framebuffer;

/**
 * @brief Creates an new `PG_Framebuffer`
 * 
 * @warning Does not imply on `PG_FramebufferConstruct`.
 */
PG_Framebuffer*
PG_FramebufferNew();

/**
 * @brief Frees an `PG_Framebuffer` created by `PG_FramebufferNew`
 * 
 * @warning Does not imply on `PG_FramebufferDestruct`
 */
void
PG_FramebufferDestroy(
    PG_Framebuffer* framebuffer
);

/**
 * @brief Construct the `PG_Framebuffer`
 */
PG_Result
PG_FramebufferConstruct(
    PG_Renderer* renderer,
    PG_Framebuffer* framebuffer,
    const PG_ViewportGeometry viewport_geometry
);

/**
 * @brief Destructs the `PG_Framebuffer`
 */
void
PG_FramebufferDestruct(
    PG_Framebuffer* framebuffer
);

/**
 * @brief Sets the current `PG_Renderer` to use this `PG_Framebuffer`, this
 * should mean that *ALL* the `Use` functions should draw inside the provided
 * framebuffer.
 */
void
PG_FramebufferUse(
    PG_Framebuffer* framebuffer
);

/**
 * @brief This function resets the `PG_Renderer` to use the default framebuffer,
 * in OpenGL, that is binding the `glFramebuffer` to zero, this must be emulated
 * in the other backends in the best way possible.
 */
void
PG_FramebufferLeave(
    PG_Framebuffer* framebuffer
);

/**
 * @brief This makes the `PG_Framebuffer` assume the functionality of a texture
 * and when the `Use` is called for an `mesh` it will consider this texture
 * instead of another one.
 * 
 * @warning While this is possible in `OpenGL`, in some other API's it might
 * need some extra tweeks to emulate this condition. But it is part of the
 * `Progator` canonical API.
 */
void
PG_FramebufferBeTexture(
    PG_Framebuffer* framebuffer,
    const PG_U8 slot
);

#endif