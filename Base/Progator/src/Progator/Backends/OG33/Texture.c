/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Backends/OG33/Texture.h"

PG_BackendsOG33Texture*
PG_BackendsOG33TextureNew()
{
    PG_BackendsOG33Texture* new_texture =
        (PG_BackendsOG33Texture*)(
            NK_AllocatorGet(sizeof(PG_BackendsOG33Texture*))
        );
    return new_texture;
}

void
PG_BackendsOG33TextureDestruct(
    PG_BackendsOG33Texture* texture
)
{
    NK_AllocatorFree(texture);
}

void
PG_BackendsOG33TextureConstruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Texture* texture
)
{
    glGenTextures(1, &texture->handle);
    texture->width = 0;
    texture->height = 0;
}

void
PG_BackendsOG33TextureDestruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Texture* texture
)
{
    glDeleteTextures(1, &texture->handle);
}

void
PG_BackendsOG33TextureUse(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Texture* texture,
    const PG_U8 slot
)
{
    glBindTexture(GL_TEXTURE_2D, texture->handle);
    glActiveTexture(GL_TEXTURE0 + slot);
}

void
PG_BackendsOG33TextureSetData(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Texture* texture,
    const void* data,
    const PG_Size data_size,
    const PG_U32 width,
    const PG_U32 height
)
{
    /** We skip binding because we assume you have Use() the function: */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    /**
     * NOTE: Copy the image, WE EXPECT a RGBA 8 buffer, this is Progator
     * standard.
     */
    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA,
        width,
        height,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        data
    );

    glGenerateMipmap(GL_TEXTURE_2D);

    /** Set the dimensions: */
    texture->width = width;
    texture->height = height;
}