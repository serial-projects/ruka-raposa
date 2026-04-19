/**
 * Konigs Infrastructure by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read `LICENSE.md` on the project root.
 */
#ifndef EGConfig_h
#define EGConfig_h

/** Echsenkonig/VM/Memory.h: */

/**
 * @brief This sets how big is an `EG_MemoryChunk`, usually you want sizes 
 * enough to not be too slow to read or too big to be holding on to.
 */
#define EG_VM_MEMORY_CHUNK_SIZE                                                 512

/**
 * @brief This sets how lazy resizes we going to have on the memory.
 */
#define EG_VM_MEMORY_CHUNK_RESIZE                                               32

#endif