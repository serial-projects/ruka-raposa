/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "Engine/Engine.h"

int 
main(
    int argc,
    char *argv[]    
)
{
    /**
     * We need to initialize all the submodules.
     */
    EN_Init();

    /**
     * Create an new `EN_Instance`
     */
    EN_Instance instance;
    
    EN_InstanceConstruct(&instance);
    EN_InstanceLoop(&instance);
    EN_InstanceDestruct(&instance);

    /**
     * After (or if) the game closes, we want to shutdown all the submodules.
     */
    EN_Quit();

    /** 
     * TODO: Return on the future, the "global return code", determined in the
     * `EN_SharedCore`, which is a way for scripts to say what return code the
     * game might have.
     */
    return 0;
}