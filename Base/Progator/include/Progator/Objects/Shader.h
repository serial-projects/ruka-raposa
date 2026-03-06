/**
 * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
 * Pro'Gator "Progator" is part of the Ruka Raposa Project.
 * 
 * Project is under GPL3-license, read LICENSE.md on the root.
 */
#ifndef PGObjectsShader_h
#define PGObjectsShader_h

#include "Progator/Core/Base.h"
#include "Progator/Core/Pointers.h"
#include "Progator/Types/Basics.h"
#include "Progator/Types/Specifications.h"
#include "Progator/Objects/Renderer.h"

typedef struct PG_Shader
{
    void* backend_object;
    PG_Renderer* renderer;
} PG_Shader;

PG_Shader* PG_ShaderNew();
void PG_ShaderDestroy(PG_Shader* shader);
void PG_ShaderConstruct(PG_Base* base, PG_Renderer* renderer, PG_Shader* shader);
void PG_ShaderDestruct(PG_Base* base, PG_Shader* shader);
PG_Result PG_ShaderBeginCompilation(PG_Base* base, PG_Shader* shader);
PG_Result PG_ShaderLoadVertexShader(PG_Base* base, PG_Shader* shader, const PG_U8* buffer);
PG_Result PG_ShaderLoadFragmentShader(PG_Base* base, PG_Shader* shader, const PG_U8* buffer);
PG_Result PG_ShaderLoadGeometryShader(PG_Base* base, PG_Shader* shader, const PG_U8* buffer);
PG_Result PG_ShaderFinishCompilation(PG_Base* base, PG_Shader* shader);
void PG_ShaderUse(PG_Base* base, PG_Shader* shader);
void PG_ShaderSetData(PG_Base* base, PG_Shader* shader, const PG_U8 slot, const void* data, const PG_Size data_size);

#endif
