/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGObjectsTexture_h
#define PGObjectsTexture_h

#include "Progator/Core/Base.h"
#include "Progator/Core/Pointers.h"
#include "Progator/Types/Basics.h"
#include "Progator/Objects/Renderer.h"

/**
 * An texture is a image that is used to give aspect to an mesh, this image
 * is passed as an sequence of bytes to the `GPU` and must have an size and
 * slot it might be used. Some shaders support one or two images to be drawn
 * at the same time.
 * 
 * @brief Contains an image for the `mesh` to use.
 */
typedef struct PG_Texture
{
    /**
     * @brief Contains the backend object for the `PG_Shader`
     */
    void* backend_object;

    /**
     * @brief Contains the `PG_Renderer` we are currently attached to, it will
     * provide the `PG_Pointers*` for the `PG_Shader` to work with.
     */
    PG_Renderer* renderer;
} PG_Texture;

/**
 * @brief Creates an new `PG_Texture`
 * 
 * @warning Does not imply in `PG_TextureConstruct`
 */
PG_Texture*
PG_TextureNew();

/**
 * @brief Frees an `PG_Texture` created by `PG_TextureNew`
 */
void
PG_TextureDestruct(
    PG_Texture* texture
);

/**
 * @brief Constructs an `PG_Texture`
 */
void
PG_TextureConstruct(
    PG_Base* base,
    PG_Renderer* renderer,
    PG_Texture* texture
);

/**
 * @brief Destruct an `PG_Texture`
 */
void
PG_TextureDestruct(
    PG_Base* base,
    PG_Texture* texture
);

/**
 * @brief Set the `PG_Renderer` to start using `PG_Texture` in a certain slot.
 */
void
PG_TextureUse(
    PG_Base* base,
    PG_Texture* texture,
    const PG_U8 slot
);

/**
 * @brief Set the `PG_Renderer` to copy the `data` to the `buffer`. You must
 * provide an `data_size` and size for your image (or it won't work), the buffer
 * must contain an `data` organized in the RGBA format!
 */
void
PG_TextureSetData(
    PG_Base* base,
    PG_Texture* texture,
    const void* data,
    const PG_Size data_size,
    const PG_U32 width,
    PG_U32 height
);

#endif