# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

# NOTE: This is a interface containing everything we need to compile the
# Engine, which is the main submodule, it requires at least:
#       RR_Base: NK, 3xjson, etc.
#       RR_ThirdParty: SDL, SDL_TTF, etc.
#       RR_Ruka: Slvgs (Renderer), etc.
add_library(RR_Ruka INTERFACE)

add_dependencies(RR_Ruka RR_Base)
add_dependencies(RR_Ruka RR_ThirdParty)

target_link_libraries(RR_Ruka INTERFACE RR_Base)
target_link_libraries(RR_Ruka INTERFACE RR_ThirdParty)

# This must be the final target:
add_subdirectory(Engine)