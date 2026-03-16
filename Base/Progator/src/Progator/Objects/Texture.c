/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Texture.h"

PG_Texture*
PG_TextureNew()
{
    PG_Texture* new_texture = 
        (PG_Texture*)(
            NK_AllocatorGet(sizeof(PG_Texture))
        );
    return new_texture;
}

void
PG_TextureFree(
    PG_Texture* texture
)
{
    NK_AllocatorFree(texture);
}

void
PG_TextureConstruct(
    PG_Texture* texture,
    PG_Renderer* renderer
)
{
    texture->renderer = renderer;
    texture->backend_object = texture->renderer->pointers->texture_new();
    texture->renderer->pointers->texture_construct(
        texture->backend_object,
        texture->renderer->backend_object
    );
}

void
PG_TextureDestruct(
    PG_Texture* texture
)
{
    texture->renderer->pointers->texture_destruct(
        texture->backend_object
    );
}

void
PG_TextureUse(
    PG_Texture* texture,
    const PG_U8 slot
)
{
    texture->renderer->pointers->texture_use(
        texture->backend_object,
        slot
    );
}

void
PG_TextureSetData(
    PG_Texture* texture,
    const void* data,
    const PG_Size data_size,
    const PG_U32 width,
    PG_U32 height
)
{
    texture->renderer->pointers->texture_set_data(
        texture->backend_object,
        data,
        data_size,
        width,
        height
    );
}