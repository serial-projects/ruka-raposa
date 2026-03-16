/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGObjectsRenderer_h
#define PGObjectsRenderer_h

#include "Progator/Core/Base.h"
#include "Progator/Core/Pointers.h"
#include "Progator/Types/Basics.h"
#include "Progator/Objects/Window.h"

/**
 * @brief This contains the `renderer`, an context we should put all the things
 * we want to draw or manipulate.
 */
typedef struct PG_Renderer
{
    /**
     * @brief Contains the backend object for `PG_Renderer`
     */
    void* backend_object;

    /**
     * @brief Contains the pointer to the backend: There is a order of the
     * elements in the engine: `PG_Window` -> `PG_Renderer` -> `PG_<>`, this
     * way you define an single `PG_Renderer` and all objects become dependent
     * on the `PG_Renderer` you provide.
     */
    PG_Pointers* pointers;

    /**
     * @brief Contains the base got from the `PG_Window`
     */
    PG_Base* base;

    /**
     * @brief An renderer is attached to a window and can't be unattached. 
     * `Progator` doesn't support switching context(s) for windows. Once a
     * window is attached to a `PG_Renderer` it must stay that way until the
     * end of the `PG_Renderer`
     */
    PG_Window* window;
} PG_Renderer;

/**
 * @brief Creates an new `PG_Renderer`
 */
PG_Renderer*
PG_RendererNew();

/**
 * @brief Frees an `PG_Renderer` created by `PG_RendererNew`
 * 
 * @warning Does not imply on `PG_RendererDestruct`
 */
void
PG_RendererFree(
    PG_Renderer* renderer
);

/**
 * @brief Constructs the `PG_Renderer`
 * 
 * @warning Does not imply on `PG_RendererSetViewport`, this must be called
 * by the user, otherwise the API might create an rendering context with an
 * (0, 0) sized framebuffer.
 */
PG_Result
PG_RendererConstruct(
    PG_Renderer* renderer,
    PG_Window* window
);

/**
 * @brief Destructs the `PG_Renderer`
 */
void
PG_RendererDestruct(
    PG_Renderer* renderer
);

/**
 * @brief Sets the viewport size for the `PG_Renderer` being used.
 */
void
PG_RendererSetViewport(
    PG_Renderer* renderer,
    const PG_U16 width,
    const PG_U16 height,
    const PG_U16 x_position,
    const PG_U16 y_position
);

/**
 * @brief Demands the graphical API to render the frame.
 */
void
PG_RendererDraw(
    PG_Renderer* renderer
);

/**
 * @brief Cleans the renderer.
 */
void
PG_RendererClear(
    PG_Renderer* renderer,
    const PG_U32 rgba_color
);

/**
 * @brief Enables an certain feature of the `PG_Renderer`, those can be seen
 * in `Progator/Enums/Renderer.h`, you can disable ZTEST for example, which is
 * useful for UI's that doesn't need it anyways.
 */
void
PG_RendererEnableFeature(
    PG_Renderer* renderer,
    const PG_U8 feature
);

/**
 * @brief Disable an certain feature of the `PG_Renderer`, much like the 
 * `PG_RendererEnableFeature`, this function also expects an value from the 
 * `Progator/Enums/Renderer.h` file.
 */
void
PG_RendererDisableFeature(
    PG_Renderer* renderer,
    const PG_U8 feature
);

#endif