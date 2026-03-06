/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Backends/OG33/Window.h"

PG_BackendsOG33Window* PG_BackendsOG33WindowNew()
{
    PG_BackendsOG33Window* new_window =
        (PG_BackendsOG33Window*)(NK_malloc(sizeof(PG_BackendsOG33Window)));
    return new_window;
}

void PG_BackendsOG33WindowDestroy(
    PG_BackendsOG33Window* window
)
{
    NK_free(window);
}

PG_Result PG_BackendsOG33WindowConstruct(
    PG_Base* base,
    PG_BackendsOG33Window* window
)
{
    PG_Result good = true;
    window->os_window = 
        SDL_CreateWindow(
            "[PG/Pro's Gator - OpenGL 330 Core (Early Window)]",
            800,
            640,
            SDL_WINDOW_OPENGL
        );
    if(window->os_window == NULL)
    {
        NK_ValidatorError(
            base->attached_validator,
            1,
            "[Progator/ OpenGL33 Backend]: SDL_CreateWindow() failed due: %s",
            SDL_GetError()
        );
        good = false;
    }
    else
    {
        window->id = SDL_GetWindowID(window->os_window);
        NK_ValidatorDebug(
            base->attached_validator,
            "[Progator/ OpenGL33 Backend]: SDL_CreateWindow() has created window = %d",
            window->id
        );
    }
    return good;
}

void PG_BackendsOG33WindowDestruct(
    PG_Base* base,
    PG_BackendsOG33Window* window
)
{
    /** Destroy the window: */
    SDL_DestroyWindow(window->os_window);
}

void PG_BackendsOG33WindowDraw(
    PG_Base* base,
    PG_BackendsOG33Window* window
)
{
    /** 
     * NOTE: We don't do anything here, SDL_GLSwapWindow() is part of the
     * renderer itself, some BACKENDS might do it split, like, image an NCURSES
     * backend:
     *      [01] RendererDraw() -   Blits everything on the framebuffer and
     *                              creates the final image.
     *      [02] WindowDraw() -     Prints on the terminal the content.
     * 
     * On SDL, we don't need it, at least here, on OpenGL...
     */
    return;
}

void PG_BackendsOG33WindowSetSize(
    PG_Base* base,
    PG_BackendsOG33Window* window,
    const PG_WindowGeometry window_geometry
)
{
    SDL_SetWindowSize(
        window->os_window,
        (int)(window_geometry.width),
        (int)(window_geometry.height)
    );

    /** TODO: We always align in the center of the screen: */
    SDL_SetWindowPosition(
        window->os_window,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED
    );
}

void PG_BackendsOG33WindowSetTitle(
    PG_Base* base,
    PG_BackendsOG33Window* window,
    const PG_C8* title
)
{
    SDL_SetWindowTitle(
        window->os_window,
        title
    );
}