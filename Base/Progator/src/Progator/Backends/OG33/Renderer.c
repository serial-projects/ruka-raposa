#include "Progator/Backends/OG33/Renderer.h"
#include "Progator/Enums/Renderer.h"

PG_BackendsOG33Renderer*
PG_BackendsOG33RendererNew()
{
    PG_BackendsOG33Renderer* new_renderer = 
        (PG_BackendsOG33Renderer*)(
            NK_AllocatorGet(sizeof(PG_BackendsOG33Renderer))
        );
    return new_renderer;
}
void
PG_BackendsOG33RendererDestruct(
    PG_BackendsOG33Renderer* renderer
)
{
    NK_AllocatorFree(renderer);
}

PG_Result
PG_BackendsOG33RendererConstruct(
    PG_Base* base,
    PG_BackendsOG33Window* window,
    PG_BackendsOG33Renderer* renderer
)
{
    PG_Result good = true;

    /**
     * Set the 3.3.0 CORE OpenGL for our OG33 Backend.
     */
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_MAJOR_VERSION,
        3
    );
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_MINOR_VERSION,
        3
    );
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_PROFILE_MASK,
        SDL_GL_CONTEXT_PROFILE_CORE
    );

    /**
     * We want some smooth animations.
     */
    SDL_GL_SetAttribute(
        SDL_GL_DOUBLEBUFFER,
        1
    );

    /**
     * We work with depth size = 24 bytes and stencil size of 8 bytes.
     */
    SDL_GL_SetAttribute(
        SDL_GL_DEPTH_SIZE,
        24
    );
    SDL_GL_SetAttribute(
        SDL_GL_STENCIL_SIZE,
        8
    );

    /**
     * Set the visuals and multisamples.
     */

    /** 
     * TODO: Actually, implement this on the future... Later, do dithering for
     * some platforms. In the future, add some flag on Renderer construction
     * like "USE_MULTISAMPLE", but again, this might not be true on Vulkan.
     */

    #ifdef PG_BACKENDS_OG33_EXPERIMENTAL
        SDL_GL_SetAttribute(
            SDL_GL_MULTISAMPLEBUFFERS,
            1
        );
        SDL_GL_SetAttribute(
            SDL_GL_MULTISAMPLESAMPLES,
            4
        );
    #endif

    SDL_GL_SetAttribute(
        SDL_GL_ACCELERATED_VISUAL,
        1
    );
    
    /**
     * Debug:
     */
    SDL_GL_SetAttribute(
        SDL_GL_CONTEXT_FLAGS,
        SDL_GL_CONTEXT_DEBUG_FLAG
    );

    /** We initialize the context: */
    renderer->context = SDL_GL_CreateContext(window->os_window);
    if(renderer->context == NULL)
    {
        NK_ValidatorPushMessage(
            base->attached_validator,
            NK_VALIDATOR_LEVEL_ERROR,
            "[Progator/ OpenGL 3.3]: Failed to initialize context due: %s",
            SDL_GetError()
        );
        good = false;
        goto failed_initialize_context_ending;
    }

    /** We initialize GLAD now: */
    if(!gladLoadGLLoader((GLADloadproc)(SDL_GL_GetProcAddress)))
    {
        NK_ValidatorPushMessage(
            base->attached_validator,
            NK_VALIDATOR_LEVEL_ERROR,
            "[Progator/ OpenGL 3.3]: Failed to initialize GLAD"
        );
        good = false;
        goto failed_initialize_glad_ending;
    }

    /** Make this context be our main to this window: */
    SDL_GL_MakeCurrent(window->os_window, renderer->context);

    /**
     * NOTE: Set an early viewport to avoid total black screen.
     */
    NK_ValidatorPushMessage(
        base->attached_validator,
        NK_VALIDATOR_LEVEL_DEBUG,
        "[Progator/ OpenGL 3.3]: Setting Viewport to 800x640x0x0"
    );
    glViewport(0, 0, 800, 640);

    /**
     * For debug reasons, we want to see some information from the OpenGL
     * instance we just have open!
     */
    NK_ValidatorPushMessage(
        base->attached_validator,
        NK_VALIDATOR_LEVEL_DEBUG,
        "[Progator/ OpenGL 3.3]: GL_VENDOR = %s",
        glGetString(GL_VENDOR)
    );
    NK_ValidatorPushMessage(
        base->attached_validator,
        NK_VALIDATOR_LEVEL_DEBUG,
        "[Progator/ OpenGL 3.3]: GL_RENDERER = %s",
        glGetString(GL_RENDERER)
    );
    NK_ValidatorPushMessage(
        base->attached_validator,
        NK_VALIDATOR_LEVEL_DEBUG,
        "[Progator/ OpenGL 3.3]: GL_VERSION = %s",
        glGetString(GL_VERSION)
    );

    /**
     * NOTE: By default, on OpenGL backend, we use adaptative v-sync, if that
     * fails, we try to use normal.
     */
    if(!SDL_GL_SetSwapInterval(-1))
    {
        SDL_GL_SetSwapInterval(1);
    }

    /**
     * NOTE: Initially, we want only the color buffer to be cleaning!
     */
    renderer->using_window = window;
    renderer->cleaning_buffers = GL_COLOR_BUFFER_BIT;

    failed_initialize_context_ending:
    failed_initialize_glad_ending:
    return good;
}

void PG_BackendsOG33RendererDestruct(
    PG_Base* base,
    PG_BackendsOG33Window* window,
    PG_BackendsOG33Renderer* renderer
)
{
    /** We don't need to use the window. */
    SDL_GL_DestructContext(renderer->context);
}

void PG_BackendsOG33RendererSetViewport(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    const PG_U16 width,
    const PG_U16 height,
    const PG_U16 x_position,
    const PG_U16 y_position
)
{
    glViewport(
        (GLint)(x_position),
        (GLint)(y_position),
        (GLsizei)(width),
        (GLsizei)(height)
    );
}

void PG_BackendsOG33RendererDraw(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer
)
{
    /** 
     * TODO: move this to PG_BackendsOG33WindowDraw: We don't need any special
     * code for OpenGL to render anything, all we need to do is flip the window
     * and voi-a lá! The window is drawn!
     */
    SDL_GL_SwapWindow(
        renderer->using_window->os_window
    );
}

void PG_BackendsOG33RendererClear(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    const PG_U32 rgba_color
)
{
    /** We need to set the OpenGL color: */
    glClearColor(
        (PG_F32)( ((rgba_color & 0xFF000000) >> 24) ) / (PG_F32)(255),
        (PG_F32)( ((rgba_color & 0x00FF0000) >> 16) ) / (PG_F32)(255),
        (PG_F32)( ((rgba_color & 0x0000FF00) >> 8)  ) / (PG_F32)(255),
        (PG_F32)( ((rgba_color & 0x000000FF)) )
    );

    glClear(renderer->cleaning_buffers);
}

void PG_BackendsOG33RendererEnableFeature(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    const PG_U8 feature
)
{
    switch(feature)
    {
        case PG_ENUMS_RENDERER_FEATURE_DEPTH_TEST:
            /** NOTE: We do this to avoid messing with the bits later: */
            renderer->cleaning_buffers = 
                (renderer->cleaning_buffers & GL_DEPTH_BUFFER_BIT)
                ? renderer->cleaning_buffers
                : renderer->cleaning_buffers ^ GL_DEPTH_BUFFER_BIT;
            glEnable(GL_DEPTH_TEST);
            break;
        case PG_ENUMS_RENDERER_FEATURE_STENCIL_TEST:
            renderer->cleaning_buffers = 
                (renderer->cleaning_buffers & GL_STENCIL_BUFFER_BIT)
                ? renderer->cleaning_buffers
                : renderer->cleaning_buffers ^ GL_STENCIL_BUFFER_BIT;
            glEnable(GL_STENCIL_TEST);
            break;
        default:
            break;
    };
}

void PG_BackendsOG33RendererDisableFeature(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    const PG_U8 feature
)
{
    switch(feature)
    {
        case PG_ENUMS_RENDERER_FEATURE_DEPTH_TEST:
            /** NOTE: We do this to avoid messing with the bits later: */
            renderer->cleaning_buffers = 
                !(renderer->cleaning_buffers & GL_DEPTH_BUFFER_BIT)
                ? renderer->cleaning_buffers
                : renderer->cleaning_buffers ^ GL_DEPTH_BUFFER_BIT;
            glDisable(GL_DEPTH_TEST);
            break;
        case PG_ENUMS_RENDERER_FEATURE_STENCIL_TEST:
            renderer->cleaning_buffers = 
                !(renderer->cleaning_buffers & GL_STENCIL_BUFFER_BIT)
                ? renderer->cleaning_buffers
                : renderer->cleaning_buffers ^ GL_STENCIL_BUFFER_BIT;
            glDisable(GL_STENCIL_TEST);
        default:
            break;
    };
}