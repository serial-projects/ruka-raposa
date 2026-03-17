# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

# Load NK:
include(RR_SetupNK)
add_subdirectory(NK)

# Load Progator:
include(RR_SetupPG)
add_subdirectory(Progator)

# This creates an main interface called: `RR_Base`, this will provide access to
# the `NK` module, the `3xjson` module and so on, everything that is base for
# the engine itself, even `Progator` which is a library for graphical
# development and interface for generics.
add_library(RR_Base INTERFACE)
target_link_libraries(RR_Base INTERFACE NK::NK-static)
target_link_libraries(RR_Base INTERFACE PG::PG-static)