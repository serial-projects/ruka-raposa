/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#include "Engine/Mode/Base.h"
#include "Engine/Redirects.h"

EN_Mode*
EN_ModeNew()
{
    EN_Mode* new_mode =
        (EN_Mode*)(
            NK_AllocatorGet(sizeof(EN_Mode))
        ); 
    return new_mode;
}

void
EN_ModeFree(
    EN_Mode* mode
)
{
    NK_AllocatorFree(mode);
}

void
EN_ModeConstruct(
    EN_Mode* mode,
    void* userdata,
    EN_ModeImplementations* implementations
)
{
    mode->userdata = userdata;
    mode->implementations = implementations;
}

void
EN_ModeDestruct(
    EN_Mode* mode
)
{
    mode->implementations = NULL;
    mode->userdata = NULL;
}

void
EN_ModeTick(
    EN_Mode* mode
)
{
    mode->implementations->tick(
        mode->userdata
    );
}

void
EN_ModeDraw(
    EN_Mode* mode
)
{
    mode->implementations->draw(
        mode->userdata
    );
}