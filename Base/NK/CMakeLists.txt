# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

cmake_minimum_required(VERSION 3.20)
project(
    NK
    VERSION 1.0
)

# This changes Config.h:
function(NK_Prefetch)
    
endfunction(NK_Prefetch)

function(NK_ConstructTarget)
    # Set the files & the new target:
    file(GLOB_RECURSE NK_SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")
    add_library(NK STATIC ${NK_SOURCES})

    # Set the properties:
    set_target_properties(NK PROPERTIES C_STANDARD 90)
    set_target_properties(NK PROPERTIES C_STANDARD_REQUIRED ON)
    set_target_properties(NK PROPERTIES C_EXTENSIONS OFF)
    target_link_libraries(NK PRIVATE RR_AddressSanitizerPresence)

    # Set the include:
    target_include_directories(NK PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
endfunction(NK_ConstructTarget)

# Define some tests for NK:
#       + Init: 
#               [Sanity Check = Yes]
#               Tests if we can start NK_Init(); NK_Quit();
#       + TableInsertion:
#               [Sanity Check = Yes]
#               This is the base for SubmergedStrings.
#       + SubmergedStrings:
#               [Sanity Check = Yes]
#               This is the base for NK_Map, NK_Set, etc. It must work.
set(NK_TESTS
    "Init"                          ON
    "TableInsertion"                ON
    "SubmergedStrings"              ON
    "MapInsertion"                  ON
    "MapIsStringDeleting"           ON
)

function(NK_AddTestToSanityCheck sanity)
    add_custom_command(
        TARGET ${sanity}
        POST_BUILD
        COMMAND ${sanity}
        COMMENT "Executing Sanity Check: ${sanity}"

    )
endfunction(NK_AddTestToSanityCheck sanity)

function(NK_FetchTests)
    # We do the tests:
    list(LENGTH NK_TESTS nk_tests_length)
    math(EXPR nk_tests_length_limit "${nk_tests_length} - 1")

    # NOTE: We also need to test everything in order:
    set(prev_test "")

    foreach(index RANGE 0 ${nk_tests_length_limit} 2)
        # Get the values here:
        list(GET NK_TESTS ${index} test)
        math(EXPR next_index "${index} + 1")
        list(GET NK_TESTS ${next_index} sanity_check)

        # Set the message:
        set(CURRENT_TEST "NK${test}Test")
        add_executable(${CURRENT_TEST} "${PROJECT_SOURCE_DIR}/tests/NK${test}.c")
        target_link_libraries(${CURRENT_TEST} PRIVATE NK)
        target_link_libraries(${CURRENT_TEST} PRIVATE RR_AddressSanitizerPresence)
        add_test(NAME ${CURRENT_TEST} COMMAND ${CURRENT_TEST} )

        # NOTE: Should we perform those test in the build time?
        if(DEFINED NK_ENFORCE_SANITY_CHECK_BUILD_TIME)
            if(NOT prev_test STREQUAL "")
                add_dependencies(${CURRENT_TEST} ${prev_test})
            endif()
            if(sanity_check)
                cmake_language(CALL NK_AddTestToSanityCheck ${CURRENT_TEST})
            endif()
            set(prev_test ${CURRENT_TEST})
        endif()
    endforeach(index RANGE 0 ${nk_tests_length_limit} 2)
endfunction(NK_FetchTests)

function(NK_Main)
    cmake_language(CALL NK_Prefetch)
    cmake_language(CALL NK_ConstructTarget)

    # Do we build the tests?
    if(DEFINED NK_BUILD_TESTS)
        cmake_language(CALL NK_FetchTests)
    endif()
endfunction(NK_Main)
cmake_language(CALL NK_Main)
