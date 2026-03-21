/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGInternalsSDLIntegration_h
#define PGInternalsSDLIntegration_h

/**
 * @brief This calls the SDL function to set the functions (SDL_malloc) to be
 * the `NK_AllocateFree` and more.
 */
void
PG_SDLIntegrationLoadMemoryFunctions();

#endif