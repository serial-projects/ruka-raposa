/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef ENCore_h
#define ENCore_h

#include "Engine/Core/Basics.h"
#include "Engine/Core/Graphics.h"

/**
 * @brief Contains the generic core passed around every mode.
 */
typedef struct EN_Core {
    /**
     * @brief Contains the basic structure for everything like running and 
     * tick_counter, etc.
     */
    EN_CoreBasics basics;

    /**
     * @brief Contains the graphical system (implemented from Progator), things
     * like `::window` and `::renderer`, which is shared across the engine.
     */
    EN_CoreGraphics graphics;
} EN_Core;

/** 
 * @brief Creates an new `EN_Core` on the heap.
 */
EN_Core*
EN_CoreNew();

/**
 * @brief Destroy the `EN_Core` created by `EN_CoreNew` function.
 */
void
EN_CoreFree(
    EN_Core* core
);

/**
 * @brief Construct the `EN_Core`.
 */
EN_Result
EN_CoreConstruct(
    EN_Core* core
);

/**
 * @brief Destruct the `EN_Core`
 */
void
EN_CoreDestruct(
    EN_Core* core
);

#endif