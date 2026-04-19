/**
 * Konigs Infrastructure by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read `LICENSE.md` on the project root.
 */
#ifndef EGVMMemory_h
#define EGVMMemory_h

#include "Echsenkonig/Types.h"

/**
 * @brief Contains an slice of the memory that is slowly allocated.
 * 
 * @warning This is just the `Header`, it means the block adjacent is the data
 * itself! Layout is: `[EG_MemoryChunkHeader, ... bytes]`!
 */
typedef struct EG_MemoryChunkHeader
{
    /**
     * @brief Contains how much of the buffer was actually initialized.
     */
    EG_U32 explored;

    /**
     * @brief This is reserved for future.
     */
    EG_U32 reserved;
} EG_MemoryChunkHeader;

/**
 * @brief Contains an place where the thread(s) can read/write memory.
 * 
 * Implementation of a supposedly segmented memory system, but the deal is that,
 * it couldn't be more false, the `EG_Memory` system does not initialize all the
 * memory at once, instead, we focus on allocate chunks of memory. Inside each
 * chunk, we might have an `uninitialized zone`, so we use lazy memory
 * initialization. This avoids memory pressure on the host system. Even if your
 * initialization was 2G, this pretends to have allocated 2G, when we need more,
 * we just `increment the list`.
 */
typedef struct EG_Memory
{
    /**
     * @brief Contains the memory buffer itself.
     */
    EG_U8** chunks;

    /**
     * @brief Contains the maximum length of the memory.
     */
    EG_Size length;
} EG_Memory;

/**
 * @brief Creates an new `EG_Memory`
 */
EG_Memory*
EG_MemoryNew();

/**
 * @brief Frees an `EG_Memory` created by `EG_MemoryNew`
 */
void
EG_MemoryFree(
    EG_Memory* memory
);

/**
 * @brief Constructs the `EG_Memory`
 */
void
EG_MemoryConstruct(
    EG_Memory* memory,
    const EG_Size capacity
);

#endif