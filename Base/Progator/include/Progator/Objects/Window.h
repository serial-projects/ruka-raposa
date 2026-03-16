/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGObjectsWindow_h
#define PGObjectsWindow_h

#include "Progator/Core/Base.h"
#include "Progator/Core/Pointers.h"
#include "Progator/Types/Basics.h"

/**
 * @brief This contains the window, an place where the `PG_Renderer` should
 * hook to.
 */
typedef struct PG_Window
{
    /**
     * @brief Contains the `PG_Base` attached to the window.
     */
    PG_Base* base;

    /**
     * @brief Contains the pointers to the backend.
     */
    PG_Pointers* pointers;

    /**
     * @brief The backend object which holds the window handler on the other
     * side.
     */
    void* backend_object;
} PG_Window;

/**
 * @brief Creates an new `PG_Window`
 * 
 * @warning Does not imply on `NK_WindowConstruct`
 */
PG_Window*
PG_WindowNew();

/**
 * @brief Frees an `PG_Window` created by `PG_WindowNew`
 * 
 * @warning Does not imply on `NK_WindowDestruct`
 */
void
PG_WindowFree(
    PG_Window* window
);

/**
 * @brief Constructs the window.
 */
PG_Result
PG_WindowConstruct(
    PG_Window* window,
    PG_Base* base,
    PG_Pointers* pointers
);

/**
 * @brief Destructs the window.
 */
void
PG_WindowDestruct(
    PG_Window* window
);

/**
 * @brief This requests the window to be drawn, if your `PG_Renderer` is only
 * an `buffer` and you need to `flip the window here`, then this is the function
 * to do it, even if your backend doesn't need it, this must be called on your
 * game.
 */
void
PG_WindowDraw(
    PG_Window* window
);

/**
 * @brief This sets the size of the window.
 */
void
PG_WindowSetSize(
    PG_Window* window,
    const PG_U16 width,
    const PG_U16 height
);

/**
 * @brief This sets the title of the window.
 */
void
PG_WindowSetTitle(
    PG_Window* window,
    const PG_C8* title
);

#endif