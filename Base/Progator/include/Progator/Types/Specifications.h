/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGTypesSpecifications_h
#define PGTypesSpecifications_h

#include "Progator/Types/Basics.h"

/**
 * \brief Contains the window geometry.
 */
typedef struct PG_WindowGeometry
{
    PG_U16      width;
    PG_U16      height;
    PG_U16      x;
    PG_U16      y;
} PG_WindowGeometry;

/**
 * \brief Contains the viewport geometry.
 */
typedef struct PG_ViewportGeometry
{
    PG_U16      width;
    PG_U16      height;
    PG_U16      x;
    PG_U16      y;
} PG_ViewportGeometry;

#endif