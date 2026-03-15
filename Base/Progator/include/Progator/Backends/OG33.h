/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGOG33_h
#define PGOG33_h

/** All the implementations: */
#include "Progator/Backends/OG33/Window.h"
#include "Progator/Backends/OG33/Renderer.h"
#include "Progator/Backends/OG33/Shader.h"
#include "Progator/Backends/OG33/Mesh.h"
#include "Progator/Backends/OG33/Framebuffer.h"
#include "Progator/Backends/OG33/Texture.h"

/** Pointers we need to hold: */
#include "Progator/Core/Pointers.h"

PG_Pointers*
PG_BackendsOG33Get();

#endif
