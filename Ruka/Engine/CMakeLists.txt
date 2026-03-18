# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

cmake_minimum_required(VERSION 3.20)
project(
    RREngine
    VERSION 1.0
)

# We require several things to be online:
include(RR_ANSICDemand)
include(RR_ASanSupport)

# We glob the files:
file(GLOB_RECURSE en_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
add_library(EN_Static STATIC ${en_sources})

# We want the whole core to be built before everything else.
add_dependencies(EN_Static RR_Base)
add_dependencies(EN_Static RR_ThirdParty)

# Start linking the libraries here:
target_link_libraries(EN_Static PUBLIC RR_ASanSupportInterface)
target_link_libraries(EN_Static PUBLIC RR_ANSICDemandInterface)
target_link_libraries(EN_Static PUBLIC RR_Ruka)
target_include_directories(EN_Static PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Constructed this? Fine, we can construct our engine, finally:
add_executable(EN_App "${CMAKE_CURRENT_SOURCE_DIR}/app/main.c")
target_link_libraries(EN_App PUBLIC EN_Static)
install(TARGETS EN_App RUNTIME DESTINATION bin)