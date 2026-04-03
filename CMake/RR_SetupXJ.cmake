# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

# Set some important variables for the NK project.
message(STATUS "Setting XJ compilation variables")
set(XJ_ENABLE_ASAN ${RR_ENABLE_ASAN})
set(XJ_SHARED OFF)
set(XJ_STATIC ON)
set(XJ_TESTS ON)