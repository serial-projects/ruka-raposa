/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Texture.h"

PG_Texture* PG_TextureNew()
{
    PG_Texture* new_texture = (PG_Texture*)(
        NK_AllocatorGet(sizeof(PG_Texture))
    );
    return new_texture;
}

void PG_TextureDestruct(
    PG_Texture* texture
)
{
    NK_AllocatorFree(texture);
}

void PG_TextureConstruct(
    PG_Base* base,
    PG_Renderer* renderer,
    PG_Texture* texture
)
{
    texture->renderer = renderer;
    texture->backend_object = 
        texture->
            renderer->
            window->
            pointers->
            texture_new();
    texture->
        renderer->
        window->
        pointers->
        texture_construct(
            texture->
                renderer->
                window->
                base,
            texture->
                renderer->
                backend_object,
            texture->backend_object
        );
}

void PG_TextureDestruct(
    PG_Base* base,
    PG_Texture* texture
)
{
    texture->
        renderer->
        window->
        pointers->
        texture_destruct(
            texture->
                renderer->
                window->
                base,
            texture->
                renderer->
                backend_object,
            texture->backend_object
        );
    texture->
        renderer->
        window->
        pointers->
        texture_destruct(
            texture->backend_object
        );
}

void PG_TextureUse(
    PG_Base* base,
    PG_Texture* texture,
    const PG_U8 slot
)
{
    texture->
        renderer->
        window->
        pointers->
        texture_use(
            texture->
                renderer->
                window->
                base,
            texture->
                renderer->
                backend_object,
            texture->backend_object,
            slot
        );
}

void PG_TextureSetData(
    PG_Base* base,
    PG_Texture* texture,
    const void* data,
    const PG_Size data_size,
    const PG_U32 width,
    PG_U32 height
)
{
    texture->
        renderer->
        window->
        pointers->
        texture_set_data(
            texture->
                renderer->
                window->
                base,
            texture->
                renderer->
                backend_object,
            texture->backend_object,
            data,
            data_size,
            width,
            height
        );
}