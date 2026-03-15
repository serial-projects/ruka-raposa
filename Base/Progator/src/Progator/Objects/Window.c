/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Window.h"

PG_Window* PG_WindowNew()
{
    PG_Window* new_window =
        (PG_Window*)(
            NK_AllocatorGet(sizeof(PG_Window))
        );
    return new_window;
}

void PG_WindowFree(
    PG_Window* window
)
{
    NK_AllocatorFree(window);
}

PG_Result PG_WindowConstruct(
    PG_Window* window,
    PG_Base* use_base,
    PG_Pointers* use_pointers
)
{
    window->base = use_base;
    window->pointers = use_pointers;

    /** Create the window: */
    window->backend_object = 
        window->
            pointers->
            window_new();

    return 
        window->
            pointers->
            window_construct(window->base, window->backend_object);
}

void PG_WindowDestruct(
    PG_Window* window
)
{
    window->
        pointers->
        window_destruct(
            window->base,
            window->backend_object
        );
    window->
        pointers->
        window_free(
            window->backend_object
        );

    /** 
     * NOTE: This is actually good, if you try to do any renderer operation, it
     * will immediately crash in a Segmentation Violation, because once you
     * deinitialize the window, you can't use it again, so in this case, it is
     * NOT C bug but a programming overkill.
     *  [01] - Shader, Mesh, Framebuffers and Texture (Big Four)
     *  [02] - Renderer
     *  [03] (and final) - Window
     * 
     * This is the order you should FREE things.
     */
    window->pointers    = NULL;
    window->base        = NULL;
}

void PG_WindowDraw(
    PG_Window* window
)
{
    window->
        pointers->
        window_draw(
            window->base,
            window->backend_object
        );
}

void PG_WindowSetSize(
    PG_Window* window,
    const PG_WindowGeometry window_geometry
)
{
    window->
        pointers->
        window_set_size(
            window->base,
            window->backend_object,
            window_geometry
        );
}

void PG_WindowSetTitle(
    PG_Window* window,
    const PG_C8* title
)
{
    window->
        pointers->
        window_set_title(
            window->base,
            window->backend_object,
            title
        );
}