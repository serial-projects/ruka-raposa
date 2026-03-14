# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

# Generic Header: +3.20 CMAKE Required, Project: Ruka Raposa.
cmake_minimum_required(VERSION 3.20)
project(
    RukaRaposa
    VERSION 1.0
)

# We need to enable testing, some modules like `NK` can support tests.
enable_testing()

# Define several options for the RR project:
option(RR_ENABLE_ASAN "If ASAN should be enabled on the project" OFF)
option(RR_ENABLE_TESTS "If tests should be considered" OFF)

# We import our functions from the library:
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(RR_SetupNK)

function(RR_Main)
    # We also need to add the `NK_ThirdParty` to the main universe, after all,
    # `Progator` an `RR_Base` element depends on `SDL` for example.
    add_subdirectory(ThirdParty)

    # NOTE: This should add RR_Base which is a interface containing everything
    # like `NK` (our vector implementations and all), `3xjson` which is our
    # JSON parser and even `Progator` the abstraction layer for graphics.
    add_subdirectory(Base)
endfunction()

# Call the main entry point:
cmake_language(CALL RR_Main)