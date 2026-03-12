# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

# This includes the modules:
add_subdirectory(NK)

# This creates an main interface called: `RR_Base`, this will provide access to
# the `NK` module, the `3xjson` module and so on, everything that is base for
# the engine itself, even `Progator` which is a library for graphical
# development and interface for generics.
add_library(RR_Base INTERFACE)
target_link_libraries(RR_Base INTERFACE NK)