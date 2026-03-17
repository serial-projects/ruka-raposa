# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

cmake_minimum_required(VERSION 3.20)
project(
    Progator
    VERSION 1.0
)

# Set the Progator:
option(PG_ENABLE_ASAN "If you want to enable ASan" OFF)
option(PG_STATIC "Build Progator .a file" ON)
option(PG_SHARED "Build Progator .so file" OFF)
set(PG_VENDOR_NAME "Ruka Raposa")

# Set the list:
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")
include(PG_ASanSupport)

# Make the context of the headers:
add_library(PG_Headers INTERFACE)
target_include_directories(PG_Headers INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Glob the files:
file(GLOB_RECURSE pg_sources "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# Find all the necessary dependencies:
add_library(PG_Libraries INTERFACE)
function(PG_TryToAddLibrary library)
    if(TARGET ${library})
        target_link_libraries(PG_Libraries INTERFACE ${library})
        add_dependencies(PG_Libraries ${library})
        message(STATUS "Found ${library}")
    else()
        message(STATUS "Could not find: ${library}")
    endif()
endfunction()

# This is what must be around on the enviroment:
cmake_language(CALL PG_TryToAddLibrary NK::NK-static)
cmake_language(CALL PG_TryToAddLibrary SDL3::SDL3-static)
cmake_language(CALL PG_TryToAddLibrary GLAD)

# Create PG::PG-static:
if(PG_STATIC)
    add_library(PG_Static STATIC ${pg_sources})
    target_link_libraries(PG_Static PUBLIC PG_Headers)
    target_link_libraries(PG_Static PRIVATE PG_ASanSupportInterface)
    target_link_libraries(PG_Static PRIVATE PG_Libraries)
    add_library(PG::PG-static ALIAS PG_Static)
endif()

# Create PG::PG-shared:
if(PG_SHARED)
    add_library(PG_Shared ${pg_sources})
    target_link_libraries(PG_Shared PUBLIC PG_Headers)
    target_link_libraries(PG_Shared PRIVATE PG_ASanSupportInterface)
    target_link_libraries(PG_Shared PRIVATE PG_Libraries)
    add_library(PG::PG-shared ALIAS PG_Shared)
endif()

# Message:
message(STATUS "[[ Progator \"${PG_VENDOR_NAME}\" - Version: ${PROJECT_VERSION} ]]")
message(STATUS "Enable Static:  ${PG_STATIC}")
message(STATUS "Enable Shared:  ${PG_SHARED}")
message(STATUS "Enable ASan:    ${PG_ENABLE_ASAN}")
message(STATUS "[[ Progator \"${PG_VENDOR_NAME}\" - Version: ${PROJECT_VERSION} ]]")