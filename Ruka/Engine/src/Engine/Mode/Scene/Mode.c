/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Mode/Scene/Mode.h"
#include "Engine/Redirects/NK.h"

EN_SceneMode*
EN_SceneModeNew()
{
    EN_SceneMode* new_mode =
        (EN_SceneMode*)(
            NK_AllocatorGet(sizeof(EN_SceneMode))
        );
    return new_mode;
}

void
EN_SceneModeFree(
    EN_SceneMode* mode
)
{
    NK_AllocatorFree(mode);
}

void
EN_SceneModeConstruct(
    EN_SceneMode* mode,
    EN_Core* linking_core
)
{
    mode->linked_core = linking_core;
}

void
EN_SceneModeDestruct(
    EN_SceneMode* mode
)
{
    /** After saving and all ... */
    mode->linked_core = NULL;
}

static
void
P_EN_HandleKeyboardInput(
    EN_SceneMode* mode
)
{
    SDL_Event event_handler;
    while(SDL_PollEvent(&event_handler) != 0)
    {
        switch(event_handler.type)
        {
            case SDL_EVENT_QUIT:
                mode->linked_core->basics.flags_bits.running = false;
                break;
            default:
                NK_ValidatorPushMessage(
                    &mode->linked_core->basics.master_validator,
                    NK_VALIDATOR_LEVEL_LOG,
                    "Got an SDL event, type = %d",
                    (int)(event_handler.type)
                );
                break;
        };
    }
}

void
EN_SceneModeTick(
    EN_SceneMode* mode
)
{
    /** NOTE: Begin the pipeline: */
    P_EN_HandleKeyboardInput(mode);
}

void
EN_SceneModeDraw(
    EN_SceneMode* mode
)
{
    /** Clean the Window: */
    PG_RendererClear(&mode->linked_core->graphics.renderer, 0x08837000);

    /** Draw the Window: */
    PG_RendererDraw(&mode->linked_core->graphics.renderer);
    PG_WindowDraw(&mode->linked_core->graphics.window);
}
