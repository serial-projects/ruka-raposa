/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Mode/Initialization/Implementation.h"
#include "Engine/Mode/Initialization/Mode.h"
#include "Engine/Redirects.h"

static
struct EN_ModeImplementations EN_InitializationModeImplementations = 
{ 
    (EN_ModeTickFunction)(EN_InitializationModeTick),
    (EN_ModeDrawFunction)(EN_InitializationModeDraw)
};

EN_InitializationModeImplementation*
EN_InitializationModeImplementationNew()
{
    EN_InitializationModeImplementation* new_implementation = 
        (EN_InitializationModeImplementation*)(
            NK_AllocatorGet(sizeof(EN_InitializationModeImplementation))
        );
    return new_implementation;
}

void
EN_InitializationModeImplementationFree(
    EN_InitializationModeImplementation* implementation
)
{
    NK_AllocatorFree(implementation);
}

void
EN_InitializationModeImplementationConstruct(
    EN_InitializationModeImplementation* implementation,
    EN_Core* linking_core
)
{
    implementation->implementations = &EN_InitializationModeImplementations;

    /** Assign the userdata to be this: */
    implementation->userdata = (void*)(EN_InitializationModeNew());
    EN_InitializationModeConstruct(
        (EN_InitializationMode*)(implementation->userdata),
        linking_core
    );
}

void
EN_InitializationModeImplementationDestruct(
    EN_InitializationModeImplementation* implementation
)
{
    /** De-assign the userdata: */
    EN_InitializationModeDestruct(
        (EN_InitializationMode*)(implementation->userdata)
    );
    EN_InitializationModeFree(
        (EN_InitializationMode*)(implementation->userdata)
    );
    implementation->userdata = NULL;

    /**
     * Set the implementation to NULL, any other call on it will SIGSEGV, which
     * means, by the definition, we have a null, you trying to act on a element
     * after its deletion, bro!
     */
    implementation->implementations = NULL;
}
