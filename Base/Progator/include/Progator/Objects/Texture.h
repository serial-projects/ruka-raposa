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
#include "Progator/Types/Specifications.h"
#include "Progator/Objects/Renderer.h"

typedef struct PG_Texture
{
    void* backend_object;
    PG_Renderer* renderer;
} PG_Texture;

PG_Texture* PG_TextureNew();
void PG_TextureDestroy(PG_Texture* texture);
void PG_TextureConstruct(PG_Base* base, PG_Renderer* renderer, PG_Texture* texture);
void PG_TextureDestruct(PG_Base* base, PG_Texture* texture);
void PG_TextureUse(PG_Base* base, PG_Texture* texture, const PG_U8 slot);
void PG_TextureSetData(PG_Base* base, PG_Texture* texture, const void* data, const PG_Size data_size, const PG_U32 width, PG_U32 height);


#endif