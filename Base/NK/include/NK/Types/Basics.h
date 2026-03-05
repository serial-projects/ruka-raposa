/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef NKTypesBasics_h
#define NKTypesBasics_h

#include <stdint.h>
#include <stdlib.h>

/** Expose some basic types we demand for the NK. */

typedef int8_t          NK_S8;
typedef uint8_t         NK_U8;
typedef int16_t         NK_S16;
typedef uint16_t        NK_U16;
typedef int32_t         NK_S32;
typedef uint32_t        NK_U32;
typedef int64_t         NK_S64;
typedef uint64_t        NK_U64;

typedef char            NK_C8;
typedef uint8_t         NK_Boolean;
typedef uint8_t         NK_Result;

typedef size_t          NK_Size;

/** Define Boolean: */
#ifndef true 
    #define true 1
#endif

#ifndef false
    #define false 0
#endif

#endif