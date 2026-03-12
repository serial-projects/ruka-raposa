# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

# Set includes all the ThirdParty into a interface called `RR_ThirdParty`, this
# includes `SDL`, `SDL_Image` and more. This `SDL` is compiled in a static way
# to avoid distributing the game with `.so` or `.dll` hell.

# Setup zlib:
add_subdirectory(zlib)

# Setup for SDL3:
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(SDL_DISABLE_INSTALL OFF)
set(SDL_TESTS OFF)

set(SDL_STATIC ON)
set(SDL_SHARED OFF)

set(SDL_X11 ON)
set(SDL_WAYLAND ON)
set(SDL_FRIBIDI OFF)
set(SDL_WAYLAND_LIBDECOR OFF)
set(SDL_VENDOR_INFO "Ruka Raposa Team")
add_subdirectory(SDL)

# Setup for SDL_image:
set(CMAKE_FIND_PACKAGE_PREFER_CONFIG TRUE)
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_BINARY_DIR}/SDL")

set(BUILD_SHARED_LIBS OFF)
set(SDLIMAGE_ZLIB ON CACHE BOOL "" FORCE)
set(SDLIMAGE_ZLIB_SHARED OFF CACHE BOOL "" FORCE)
set(SDLIMAGE_VENDORED OFF)
add_subdirectory(SDL_image)

# Setup for SDL_ttf:
set(SDLTTF_HARFBUZZ OFF CACHE BOOL "" FORCE)
set(SDLTTF_VENDORED OFF)
add_subdirectory(SDL_ttf)

# Setup for GLAD:
add_subdirectory(GLAD)

# Setup for CGLM:
set(CGLM_SHARED OFF)
set(CGLM_STATIC ON)
set(CGLM_USE_C99 OFF)
set(CGLM_USE_TEST OFF)
add_subdirectory(CGLM)

# Set the `RR_ThirdParty` interface.
add_library(RR_ThirdParty INTERFACE)
target_link_libraries(RR_ThirdParty INTERFACE SDL3::SDL3-static)
target_link_libraries(RR_ThirdParty INTERFACE SDL3_image::SDL3_image-static)
target_link_libraries(RR_ThirdParty INTERFACE SDL3_ttf::SDL3_ttf-static)
target_link_libraries(RR_ThirdParty INTERFACE GLAD)