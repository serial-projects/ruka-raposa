/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGBackendsOG33Texture_h
#define PGBackendsOG33Texture_h

#include "Progator/Backends/OG33/Config.h"
#include "Progator/Backends/OG33/GL.h"
#include "Progator/Backends/OG33/Types.h"
#include "Progator/Backends/OG33/Renderer.h"
#include "Progator/Core/Base.h"

typedef struct PG_BackendsOG33Texture
{
    /**
     * @brief This contains the handle to the OpenGL texture object.
     */
    PG_BackendsOG33Texture2DHandle handle;

    /**
     * @brief This contains the width of the texture.
     */
    PG_U32 width;

    /**
     * @brief This contains the height of the texture.
     */
    PG_U32 height;
} PG_BackendsOG33Texture;

PG_BackendsOG33Texture*
PG_BackendsOG33TextureNew();

void
PG_BackendsOG33TextureDestroy(
    PG_BackendsOG33Texture* texture
);

void
PG_BackendsOG33TextureConstruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Texture* texture
);

void
PG_BackendsOG33TextureDestruct(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Texture* texture
);

void
PG_BackendsOG33TextureUse(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Texture* texture,
    const PG_U8 slot
);

void
PG_BackendsOG33TextureSetData(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    PG_BackendsOG33Texture* texture,
    const void* data,
    const PG_Size data_size,
    const PG_U32 width,
    const PG_U32 height
);

#endif
