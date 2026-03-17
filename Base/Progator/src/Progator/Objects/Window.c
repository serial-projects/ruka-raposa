/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Progator/Objects/Window.h"

PG_Window*
PG_WindowNew()
{
    PG_Window* new_window =
        (PG_Window*)(
            NK_AllocatorGet(sizeof(PG_Window))
        );
    return new_window;
}

void
PG_WindowFree(
    PG_Window* window
)
{
    NK_AllocatorFree(window);
}

PG_Result
PG_WindowConstruct(
    PG_Window* window,
    PG_Base* base,
    PG_Pointers* pointers
)
{
    window->base = base;
    window->pointers = pointers;
    window->backend_object = window->pointers->window_new();
    return (
        window->pointers->window_construct(
            window->backend_object,
            window->base
        )
    );
}

void
PG_WindowDestruct(
    PG_Window* window
)
{
    window->pointers->window_destruct(
        window->backend_object
    );
}

void
PG_WindowDraw(
    PG_Window* window
)
{
    window->pointers->window_draw(
        window->backend_object
    );
}

void
PG_WindowSetSize(
    PG_Window* window,
    const PG_U16 width,
    const PG_U16 height
)
{
    window->pointers->window_set_size(
        window->backend_object,
        width,
        height
    );
}

void
PG_WindowSetTitle(
    PG_Window* window,
    const PG_C8* title
)
{
    window->pointers->window_set_title(
        window->backend_object,
        title
    );
}