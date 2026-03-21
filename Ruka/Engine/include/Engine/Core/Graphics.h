/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef ENCoreGraphics_h
#define ENCoreGraphics_h

#include "Engine/Redirects.h"

typedef struct EN_CoreGraphics
{
    /**
     * @brief Contains the main window used by the core.
     */
    PG_Window window;

    /**
     * @brief Contains the main renderer used by the core, which is always
     * attached to the `EN_CoreGraphics::window`, by default, we don't have big
     * pretentions of rendering things on multiple instances (We want to be
     * compatible with `Progator` settings).
     */
    PG_Renderer renderer;

    /**
     * @brief Set the pointers.
     */
    PG_Pointers* pointers;

    /**
     * @brief This is the base for all the elements.
     */
    PG_Base base;
} EN_CoreGraphics;

/**
 * @brief Creates an new `EN_CoreGraphics`
 */
EN_CoreGraphics*
EN_CoreGraphicsNew();

/**
 * @brief Frees an `EN_CoreGraphics` created by `EN_CoreGraphicsNew`
 */
void
EN_CoreGraphicsFree(
    EN_CoreGraphics* graphics
);

/**
 * @brief Constructs an `EN_CoreGraphics`, things like: window, renderer and 
 * others.
 */
NK_Result
EN_CoreGraphicsConstruct(
    EN_CoreGraphics* graphics,
    NK_Validator* validator,
    const PG_U8 backend
);

/**
 * @brief Destructs an `EN_CoreGraphics`, things like: window, renderer and
 * others.
 */
void
EN_CoreGraphicsDestruct(
    EN_CoreGraphics* graphics
);

#endif