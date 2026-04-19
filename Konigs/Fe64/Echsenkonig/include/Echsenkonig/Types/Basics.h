/**
 * Konigs Infrastructure by Ruka Raposa Team & Contribuitors.
 * Project is under GPL3-license, read `LICENSE.md` on the project root.
 */
#ifndef EGTypesBasics_h
#define EGTypesBasics_h

#include <stdint.h>

/** Number Types: */

typedef uint8_t         EG_U8;
typedef int8_t          EG_S8;
typedef uint16_t        EG_U16;
typedef int16_t         EG_S16;
typedef uint32_t        EG_U32;
typedef int32_t         EG_S32;
typedef uint64_t        EG_U64;
typedef int64_t         EG_S64;

/** Float Types: */

typedef float           EG_F32;
typedef double          EG_F64;

/** Character Type: */
typedef EG_U8           EG_C8;

/** Logical/Misc Types: */
typedef EG_U8           EG_Boolean;
typedef EG_U8           EG_Result;
typedef EG_U64          EG_Size;

#endif