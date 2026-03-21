/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PG_h
#define PG_h

#include "Progator/Redirects.h"
#include "Progator/Core.h"
#include "Progator/Objects.h"
#include "Progator/Types.h"
#include "Progator/Backends.h"
#include "Progator/Enum.h"

/**
 * @brief Initialize all the subsystems (mostly SDL).
 */
PG_Result
PG_Construct();

/**
 * @brief Deinitialize the subsystems (mostly SDL).
 */
void
PG_Destruct();

/**
 * @brief Gets if Progator is initialized or not.
 */
const PG_Result
PG_IsConstructed();

#endif