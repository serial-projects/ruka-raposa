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
     * @brief It is a reference to a outside validator to report logs, because
     * `Progator` won't report logs to the stdout, only to the `NK_Validator`
     * attributed here.
     * 
     * @warning You must create an external validator and link it here.
     */
    NK_Validator* validator;
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
void
PG_BaseConstruct(
    PG_Base* base,
    NK_Validator* validator
);

/**
 * @brief Destructs the base.
 */
void
PG_BaseDestruct(
    PG_Base* base
);

#endif