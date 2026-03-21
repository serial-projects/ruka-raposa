/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Progator/Internals/SDLIntegration.h"
#include "Progator/Redirects.h"
#include "Progator/Types/Basics.h"

static
void*
P_PG_SDLIntegratingMallocFunction(
    PG_Size size
)
{
    /** NOTE: By default, `NK_AllocatorGet` behaves like `malloc()` */
    return NK_AllocatorGet(size);
}

static
void*
P_PG_SDLIntegratingCallocFunction(
    PG_Size m_block,
    PG_Size size
)
{
    /** NOTE: We do the manual cleaning here: */
    PG_U8* block =
        (PG_U8*)(
            NK_AllocatorGet(m_block * size)
        );
    NK_RedirectMemset(
        block,
        0,
        sizeof(PG_U8) * (m_block * size)
    );
    return (void*)block;
}

static
void*
P_PG_SDLIntegratingReallocFunction(
    void* old_block,
    PG_Size new_size 
)
{
    void* new_block = 
        (void*)(
            NK_AllocatorResizeBlock(old_block, new_size)
        );
    return new_block;
}

static
void
P_PG_SDLIntegratingFreeFunction(
    void* block
)
{
    /** This will free the block. */
    NK_AllocatorFree(block);
}

void
PG_SDLIntegrationLoadMemoryFunctions()
{
    SDL_SetMemoryFunctions(
        P_PG_SDLIntegratingMallocFunction,
        P_PG_SDLIntegratingCallocFunction,
        P_PG_SDLIntegratingReallocFunction,
        P_PG_SDLIntegratingFreeFunction
    );
}