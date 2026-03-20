/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef ENModeBase_h
#define ENModeBase_h

#include "Engine/Mode/Implementations.h"
#include "Engine/Core.h"

/**
 * @brief Contains an default implementation for any mode. The modes must follow
 * this sort of implementation.
 */
typedef struct EN_Mode
{
    /** Holds the varying part. */
    void* userdata;

    /** The implementations. */
    EN_ModeImplementations* implementations;
} EN_Mode;

/**
 * @brief Creates an new `EN_Mode`
 * 
 * @warning Does not imply in `EN_ModeConstruct`
 */
EN_Mode*
EN_ModeNew();

/**
 * @brief Frees an `EN_Mode` created by `EN_ModeNew`
 * 
 * @warning Does not imply in `EN_ModeDestruct`
 */
void
EN_ModeFree(
    EN_Mode* mode
);

/**
 * @brief Constructs an `EN_Mode`
 */
void
EN_ModeConstruct(
    EN_Mode* mode,
    void* userdata,
    EN_ModeImplementations* implementations
);

/**
 * @brief Destructs an `EN_Mode`
 */
void
EN_ModeDestruct(
    EN_Mode* mode
);

/**
 * @brief Generic function to tick.
 */
void
EN_ModeTick(
    EN_Mode* mode
);

/**
 * @brief Generic function to draw.
 */
void
EN_ModeDraw(
    EN_Mode* mode
);

#endif