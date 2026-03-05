/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */

#include "NK/NK.h"
#include "NK/Internals/Subsystems.h"

void
NK_Init()
{
    NK_SubsystemsConstruct();
}

void
NK_Quit()
{
    NK_SubsystemsDestruct();
}
