# /**
#  * Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
#  * Project is under GPL3-license, read LICENSE.md on the root.
#  */

cmake_minimum_required(VERSION 3.20)
project(
    GLAD
    VERSION 0.1.36
    LANGUAGES C
)

# Wrap the GLAD sources:
set(GLAD_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/glad/glad.c")

# Create a library named: GLAD
add_library(GLAD STATIC ${GLAD_SOURCES})
target_include_directories(GLAD PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")