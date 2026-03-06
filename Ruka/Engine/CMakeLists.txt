# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

cmake_minimum_required(VERSION 3.20)
project(
    RukaRaposaEngine
    VERSION 1.0
)

function(EN_Prefetch)
    # NOTE: There is no prefetch.
endfunction()

function(EN_ConstructTarget)
    file(GLOB_RECURSE EN_SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")
    add_library(EN STATIC ${EN_SOURCES})
    set_target_properties(EN PROPERTIES C_STANDARD 90)
    set_target_properties(EN PROPERTIES C_STANDARD_REQUIRED ON)
    set_target_properties(EN PROPERTIES C_EXTENSIONS OFF)
    target_link_libraries(())
endfunction()

function(EN_main)
    
endfunction()
