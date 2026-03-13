/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef RGCoreBase_h
#define RGCoreBase_h

#include "Redgator/Types.h"

/**
 * @brief This contains the `RG_Base` which is base for the backends to use.
 */
typedef struct RG_Base
{
    /**
     * @brief This is a counter.
     */
    NK_U64 counter;
} RG_Base;

/**
 * @brief This creates an `RG_Base` on the heap.
 */
RG_Base*
RG_BaseNew();

/**
 * @brief This frees an `RG_Base' created by `RG_BaseFree`
 */
void
RG_BaseFree(
    RG_Base* base
);

/**
 * @brief This constructs the base.
 */
void
RG_BaseConstruct(
    RG_Base* base
);

/**
 * @brief This destructs the base.
 */
void
RG_BaseDestruct(
    RG_Base* base
);

#endif