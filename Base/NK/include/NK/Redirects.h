/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef NKRedirects_h
#define NKRedirects_h

#include "NK/Types/Basics.h"
#include <memory.h>

#define NK_RedirectMalloc       malloc
#define NK_RedirectCalloc       calloc
#define NK_RedirectRealloc      realloc
#define NK_RedirectFree         free
#define NK_RedirectMemcpy       memcpy
#define NK_RedirectMemset       memset
#define NK_RedirectStrlen       strlen
#define NK_RedirectStrcmp       strcmp
#define NK_RedirectStrncmp      strncmp

#endif