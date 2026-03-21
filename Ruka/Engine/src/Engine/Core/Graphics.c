/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Core/Graphics.h"
#include "Engine/Redirects.h"

EN_CoreGraphics*
EN_CoreGraphicsNew()
{
    EN_CoreGraphics* new_graphics = 
        (EN_CoreGraphics*)(
            NK_AllocatorGet(sizeof(EN_CoreGraphics))
        );
    return new_graphics;
}

void
EN_CoreGraphicsFree(
    EN_CoreGraphics* graphics
)
{
    NK_AllocatorFree(graphics);
}

NK_Result
EN_CoreGraphicsConstruct(
    EN_CoreGraphics* graphics,
    NK_Validator* validator,
    const PG_U8 backend
)
{
    NK_Result good;

    /** Get ready to renderer: */
    graphics->pointers = PG_BackendsOG33Get();

    PG_BaseConstruct(
        &graphics->base,
        validator
    );

    /** Is our window good? */
    good = PG_WindowConstruct(
        &graphics->window,
        &graphics->base,
        graphics->pointers
    );
    if(!good)
    {
        goto bad_window_initialization_ending;
    }

    /** Is our renderer good? */
    good = PG_RendererConstruct(
        &graphics->renderer,
        &graphics->window
    );
bad_window_initialization_ending:
    return good;
}

void
EN_CoreGraphicsDestruct(
    EN_CoreGraphics* graphics
)
{
    PG_RendererDestruct(&graphics->renderer);
    PG_WindowDestruct(&graphics->window);
    PG_BaseDestruct(&graphics->base);
    graphics->pointers = NULL;
}
