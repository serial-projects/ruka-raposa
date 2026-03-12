# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

cmake_minimum_required(VERSION 3.20)
project(
    NK
    VERSION 1.0
)

# Defines the `NK` target here:
file(GLOB_RECURSE nk_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
add_library(NK STATIC ${nk_sources})
target_include_directories(NK PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Include support libraries:
target_link_libraries(NK PRIVATE RR_ASanSupportInterface)
target_link_libraries(NK PRIVATE RR_ANSICDemandInterface)