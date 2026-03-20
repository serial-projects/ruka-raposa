/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef ENModeImplementations_h
#define ENModeImplementations_h

#include "Engine/Core.h"

/**
 * @brief Implementation of the `Tick` function.
 */
typedef
void
(*EN_ModeTickFunction)(
    void* mode
);

/**
 * @brief Implementation of the `Draw` function.
 */
typedef
void
(*EN_ModeDrawFunction)(
    void* mode
);

/**
 * @brief You can describe any mode in simple functions: `EN_Construct` (this is
 * part of the standard mode anyway), `EN_Destruct`, `EN_Tick` and `EN_Draw`,
 * this contains the draw function.
 */
typedef struct EN_ModeImplementations
{
    /**
     * @brief The `EN_Tick` should handle the game processing stages.
     */
    EN_ModeTickFunction tick;

    /**
     * @brief The `EN_Draw` should draw the game and do everything related
     * to the graphical aspect of the game.
     */
    EN_ModeDrawFunction draw;
} EN_ModeImplementations;

#endif