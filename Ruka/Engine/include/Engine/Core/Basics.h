/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef ENCoreBasics_h
#define ENCoreBasics_h

#include "Engine/Types/Basics.h"

/**
 * @brief Contains the counters, runtime information that is necessary for the
 * game to run.
 */
typedef struct EN_CoreBasics
{
    /**
     * @brief The amount of ticks perfomed.
     */
    EN_U64 tick_counter;

    /**
     * @brief The amount of draw performed.
     */
    EN_U64 draw_counter;

    /**
     * @brief In a second, how many times tick() is to be called.
     */
    EN_U8 tick_rate;

    /**
     * @brief In a second, how many times draw() is to be called.
     */
    EN_U8 draw_rate;

    /**
     * @brief Contains the current mode the engine is, read:
     * `Engine/Enums/EngineModes.h` for all the modes.
     */
    EN_U8 current_mode;

    /**
     * @brief Runtime flags:
     */
    union
    {
        EN_U8 flags;
        struct {
            /**
             * @brief If the game is running.
             */
            EN_U8 running: 1;

            /**
             * @brief If we should skip the draw.
             */
            EN_U8 skip_draw: 1;

            /**
             * @brief If we should skip the tick.
             */
            EN_U8 skip_tick: 1;

            /**
             * @brief If we should skip the VM event processing.
             */
            EN_U8 skip_vm_events: 1;

            /**
             * @brief Reserved, not used.
             */
            EN_U8 resv: 4;
        } flags_bits;
    };
} EN_CoreBasics;

/**
 * @brief Create a new `EN_CoreBasics` object on the heap.
 * @warning This is most for pedantic reasons, on our regiment, we demand this.
 */
EN_CoreBasics*
EN_CoreBasicsNew();

/**
 * @brief Delete a `EN_CoreBasics` created by `EN_CoreBasicsNew` function.
 * @warning This is most for pedantic reasons.
 */
void
EN_CoreBasicsFree(
    EN_CoreBasics* basics
);

/**
 * @brief Constructs the internal (and first values).
 * 
 * @warning `EN_CoreBasics::flags::running` default is 0, always initialize it
 * later or the game won't execute.
 */
void
EN_CoreBasicsConstruct(
    EN_CoreBasics* basics
);

/**
 * @brief Destructs the `EN_CoreBasics` internal objects.
 */
void
EN_CoreBasicsDestruct(
    EN_CoreBasics* basics
);

#endif