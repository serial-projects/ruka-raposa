/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Backends/OG33/Window.h"

PG_BackendsOG33Window*
PG_BackendsOG33WindowNew()
{
    PG_BackendsOG33Window* new_window =
        (PG_BackendsOG33Window*)(
            NK_AllocatorGet(sizeof(PG_BackendsOG33Window))
        );
    return new_window;
}

void
PG_BackendsOG33WindowFree(
    PG_BackendsOG33Window* window
)
{
    NK_AllocatorFree(window);
}

PG_Result
PG_BackendsOG33WindowConstruct(
    PG_BackendsOG33Window* window,
    PG_Base* base
)
{
    PG_Result good = true;
    
    /** Set the window base: */
    window->base = base;

    window->os_window = 
        SDL_CreateWindow(
            "[PG/Pro's Gator - OpenGL 330 Core (Early Window)]",
            800,
            640,
            SDL_WINDOW_OPENGL
        );
    if(window->os_window == NULL)
    {
        NK_ValidatorPushMessage(
            window->base->validator,
            NK_VALIDATOR_LEVEL_ERROR,
            "[Progator/ OpenGL 3.3]: SDL_CreateWindow failed due: %s",
            SDL_GetError()
        );
        good = false;
    }
    else
    {
        window->id = SDL_GetWindowID(window->os_window);
        NK_ValidatorPushMessage(
            window->base->validator,
            NK_VALIDATOR_LEVEL_DEBUG,
            "[Progator/ OpenGL 3.3]: SDL_CreateWindow has created window: %d",
            window->id
        );
    }
    return good;
}

void
PG_BackendsOG33WindowDestruct(
    PG_BackendsOG33Window* window
)
{
    /** Free the window: */
    SDL_DestroyWindow(window->os_window);
}

void
PG_BackendsOG33WindowDraw(
    PG_BackendsOG33Window* window
)
{
    SDL_GL_SwapWindow(window->os_window);
}

void
PG_BackendsOG33WindowSetSize(
    PG_BackendsOG33Window* window,
    const PG_U16 width,
    const PG_U16 height
)
{
    SDL_SetWindowSize(
        window->os_window,
        (int)(width),
        (int)(height)
    );
}

void
PG_BackendsOG33WindowSetTitle(
    PG_BackendsOG33Window* window,
    const PG_C8* title
)
{
    SDL_SetWindowTitle(
        window->os_window,
        title
    );
}