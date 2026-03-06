# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

# Generic Header: +3.20 CMAKE Required, Project: Ruka Raposa.
cmake_minimum_required(VERSION 3.20)
project(
    RukaRaposa
    VERSION 1.0
)

# Set everything:
enable_testing()

#
# Base
#

set(RR_BASE "NK")

function(RR_PrepareExclusiveSymbols)
    add_library(RR_AddressSanitizerPresence INTERFACE)
    if(MSVC)
        target_compile_options(RR_AddressSanitizerPresence INTERFACE $<$<CONFIG:Debug>:/fsanitize=address /Zi>)
        target_link_options(RR_AddressSanitizerPresence INTERFACE $<$<CONFIG:Debug>:/incremental:no>)
    else()
        target_compile_options(RR_AddressSanitizerPresence INTERFACE $<$<CONFIG:Debug>:-fsanitize=address -fno-omit-frame-pointer>)
        target_link_options(RR_AddressSanitizerPresence INTERFACE $<$<CONFIG:Debug>:-fsanitize=address>)
    endif()
endfunction(RR_PrepareExclusiveSymbols)

function(RR_FetchBase)
    # NOTE: When we are building on the DEBUG branch, we enable demos for NK.
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(NK_BUILD_TESTS ON)
        set(NK_ENFORCE_SANITY_CHECK_BUILD_TIME ON)
    endif()
    foreach(required_project ${RR_BASE})
        message(STATUS "Fetching Base/${required_project}")
        add_subdirectory("Base/${required_project}")
    endforeach(required_project ${RR_BASE})
endfunction(RR_FetchBase)

#
# Third Party
#

set(RR_THIRDPARTY "SDL" "SDL_image" "SDL_ttf")

function(RR_FetchThirdPartyExportSDLConfiguration)
    # Makes SDL NOT dump on the wrong path:
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

    # Important SDL Configuration:
    set(SDL_STATIC ON)
    set(SDL_SHARED OFF)
    set(SDL_TESTS OFF)
    set(SDL_FRIBIDI OFF)
    set(SDL_WAYLAND_LIBDECOR OFF)
    set(SDL_VENDOR_INFO "Ruka Raposa Team")
endfunction(RR_FetchThirdPartyExportSDLConfiguration)

function(RR_FetchThirdParty)
    cmake_language(CALL RR_FetchThirdPartyExportSDLConfiguration)
    foreach(required_td ${RR_THIRDPARTY})
        add_subdirectory("ThirdParty/${required_td}")
    endforeach(required_td ${RR_THIRDPARTY})
endfunction(RR_FetchThirdParty)

#
# Fetch
#

# Start Preloading Everything we need:
#       + RR_FetchBase
#       + RR_FetchThirdParty
function(RR_Fetch)
    cmake_language(CALL RR_FetchBase)
    cmake_language(CALL RR_FetchThirdParty)
endfunction(RR_Fetch)

# Main:
#       + RR_PrepareExclusiveSymbols
#       + RR_Prefetch
function(RR_Main)
    cmake_language(CALL RR_PrepareExclusiveSymbols)
    cmake_language(CALL RR_Fetch)
endfunction(RR_Main)
cmake_language(CALL RR_Main)