/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGObjectsWindow_h
#define PGObjectsWindow_h

#include "Progator/Core/Base.h"
#include "Progator/Core/Pointers.h"
#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"

typedef struct PG_Window
{
    PG_Base* base;
    PG_Pointers* pointers;
    void* backend_object;
} PG_Window;

PG_Window* PG_WindowNew();
void PG_WindowDestroy(PG_Window* window);
PG_Result PG_WindowConstruct(PG_Window* window, PG_Base* use_base, PG_Pointers* use_pointers);
void PG_WindowDestruct(PG_Window* window);
void PG_WindowDraw(PG_Window* window);
void PG_WindowSetSize(PG_Window* window, const PG_WindowGeometry window_geometry);
void PG_WindowSetTitle(PG_Window* window, const PG_C8* title);

#endif