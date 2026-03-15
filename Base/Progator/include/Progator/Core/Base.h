/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGCoreBase_h
#define PGCoreBase_h

#include "Progator/Types/Basics.h"

/**
 * @brief We need to use `NK` redirect here.
 */
#include "Progator/Redirects.h"

/**
 * @brief This is the structure that is passed to any backend, it contains an
 * validator in case your backend need to report something.
 */
typedef struct PG_Base
{
    /**
     * @brief Contains an backend for message reporting.
     */
    NK_Validator* attached_validator;

    /**
     * @brief This is a estimated usage of memory for Mesh and Textures. It
     * might not be THAT reliable but, fits the needs for an estimation anyways.
     */
    PG_U64 memory_used;
} PG_Base;

/**
 * @brief Creates an new `PG_Base`
 */
PG_Base*
PG_BaseNew();

/**
 * @brief Frees the `PG_Base` created by the function `PG_BaseNew`
 */
void
PG_BaseFree(
    PG_Base* base
);

/**
 * @brief Constructs the base.
 */
PG_Result
PG_BaseConstruct(
    PG_Base* base,
    NK_Validator* use_validator
);

/**
 * @brief Destructs the base.
 */
void
PG_BaseDestruct(
    PG_Base* base
);

#endif