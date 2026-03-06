#include "Progator/Backends/OG33/Renderer.h"
#include "Progator/Enums/Renderer.h"

PG_BackendsOG33Renderer* PG_BackendsOG33RendererNew()
{
    PG_BackendsOG33Renderer* new_renderer = 
        (PG_BackendsOG33Renderer*)(NK_malloc(sizeof(PG_BackendsOG33Renderer)));
    return new_renderer;
}
void PG_BackendsOG33RendererDestroy(
    PG_BackendsOG33Renderer* renderer
)
{
    NK_free(renderer);
}

PG_Result PG_BackendsOG33RendererConstruct(
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
        NK_ValidatorError(
            base->attached_validator,
            1,
            "[Progator/ OpenGL33 Backend]: Failed to initialize Context using SDL_GL_CreateContext, got: %s",
            SDL_GetError()
        );
        good = false;
        goto failed_initialize_context_ending;
    }

    /** We initialize GLAD now: */
    if(!gladLoadGLLoader((GLADloadproc)(SDL_GL_GetProcAddress)))
    {
        NK_ValidatorError(
            base->attached_validator,
            1,
            "[Progator/ OpenGL33 Backend]: Failed to initialize GLAD"
        );
        good = false;
        goto failed_initialize_glad_ending;
    }

    /** Make this context be our main to this window: */
    SDL_GL_MakeCurrent(window->os_window, renderer->context);

    /** We set the early viewport: */
    NK_ValidatorDebug(
        base->attached_validator,
        "[Progator/ OpenGL33 Backend]: Setting Early Viewport to be: 800x640x0x0"
    );

    glViewport(0, 0, 800, 640);

    /** Debug some information: */
    NK_ValidatorDebug(
        base->attached_validator,
        "[Progator/ OpenGL33 Backend]: GL_VENDOR = %s",
        glGetString(GL_VENDOR)
    );

    NK_ValidatorDebug(
        base->attached_validator,
        "[Progator/ OpenGL33 Backend]: GL_RENDERER = %s",
        glGetString(GL_RENDERER)
    );

    NK_ValidatorDebug(
        base->attached_validator,
        "[Progator/ OpenGL33 Backend]: GL_VERSION = %s",
        glGetString(GL_VERSION)
    );

    /** We try the adaptative vsync: */
    if(!SDL_GL_SetSwapInterval(-1))
    {
        /** If this fails, then you get no VSYNC, unfortunately. */
        SDL_GL_SetSwapInterval(1);
    }

    /** We set the window we are using: */
    renderer->using_window = window;

    /** Set the current working buffers: */
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
    SDL_GL_DestroyContext(renderer->context);
}

void PG_BackendsOG33RendererSetViewport(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer,
    const PG_ViewportGeometry viewport_geometry
)
{
    glViewport(
        (GLint)viewport_geometry.x,
        (GLint)viewport_geometry.y,
        (GLsizei)viewport_geometry.width,
        (GLsizei)viewport_geometry.height
    );
}

void PG_BackendsOG33RendererDraw(
    PG_Base* base,
    PG_BackendsOG33Renderer* renderer
)
{
    /** We need to swap the window: */
    SDL_GL_SwapWindow(renderer->using_window->os_window);
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