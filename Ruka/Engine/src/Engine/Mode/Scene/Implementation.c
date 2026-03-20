/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Mode/Scene/Implementation.h"
#include "Engine/Mode/Scene/Mode.h"
#include "Engine/Redirects.h"

static
struct EN_ModeImplementations EN_SceneModeImplementations = 
{ 
    (EN_ModeTickFunction)(EN_SceneModeTick),
    (EN_ModeDrawFunction)(EN_SceneModeDraw)
};

EN_SceneModeImplementation*
EN_SceneModeImplementationNew()
{
    EN_SceneModeImplementation* new_implementation = 
        (EN_SceneModeImplementation*)(
            NK_AllocatorGet(sizeof(EN_SceneModeImplementation))
        );
    return new_implementation;
}

void
EN_SceneModeImplementationFree(
    EN_SceneModeImplementation* implementation
)
{
    NK_AllocatorFree(implementation);
}

void
EN_SceneModeImplementationConstruct(
    EN_SceneModeImplementation* implementation,
    EN_Core* linking_core
)
{
    implementation->implementations = &EN_SceneModeImplementations;

    /** Assign the userdata to be this: */
    implementation->userdata = (void*)(EN_SceneModeNew());
    EN_SceneModeConstruct(
        (EN_SceneMode*)(implementation->userdata),
        linking_core
    );
}

void
EN_SceneModeImplementationDestruct(
    EN_SceneModeImplementation* implementation
)
{
    /** De-assign the userdata: */
    EN_SceneModeDestruct(
        (EN_SceneMode*)(implementation->userdata)
    );
    EN_SceneModeFree(
        (EN_SceneMode*)(implementation->userdata)
    );
    implementation->userdata = NULL;
    
    /** Set the implementations to NULL. */
    implementation->implementations = NULL;
}
