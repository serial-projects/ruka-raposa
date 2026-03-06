/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGCoreBase_h
#define PGCoreBase_h

#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "NK/NK.h"

/**
 * NOTE: This is passed to EVERY backend, OG33, Vk12, etc.
 */
typedef struct PG_Base
{
    /**
     * \brief The only way to get messages from the backends is by the validator
     * and also handle error, for example, an unrecoverable OpenGL error is only
     * adquired by this means.
     */
    NK_Validator* attached_validator;

    /**
     * \brief Estimated amount of memory used.
     * 
     * \warning This is the ESTIMATED amount of memory inside the GPU, it
     * considers meshes and shaders passed and can only be modified by the 
     * backend.
     */
    PG_U64 memory_used;
} PG_Base;

PG_Base* PG_BaseNew();
void PG_BaseDestroy(PG_Base* base);
PG_Result PG_BaseConstruct(PG_Base* base, NK_Validator* use_validator);
void PG_BaseDestruct(PG_Base* base);

#endif