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
P_EN_SceneModeTickStageHandleKeyboardInput(
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
                break;
        };
    }
}

static
void
P_EN_SceneModeTickStageDebug(
    EN_SceneMode* mode
)
{
    if(
        (
            mode->linked_core->basics.tick_counter % 
            (mode->linked_core->basics.tick_rate * 5)
        ) == 0
    )
    {
        NK_AllocatorStatistics current_stats =
            NK_AllocatorGetCurrentStatistics();
        NK_ValidatorPushMessage(
            &mode->linked_core->basics.master_validator,
            NK_ENUMS_VALIDATOR_LEVEL_DEBUG,
            "Memory `NK` (Online Allocations): %d",
            current_stats.online_blocks
        );
        NK_ValidatorPushMessage(
            &mode->linked_core->basics.master_validator,
            NK_ENUMS_VALIDATOR_LEVEL_DEBUG,
            "Memory `NK` (Absolute Usage): %d, Maximum: %d",
            current_stats.absolute_size,
            current_stats.absolute_max
        );
    }
}

void
EN_SceneModeTick(
    EN_SceneMode* mode
)
{
    /** NOTE: Begin the pipeline: */
    P_EN_SceneModeTickStageHandleKeyboardInput(mode);
    P_EN_SceneModeTickStageDebug(mode);
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
