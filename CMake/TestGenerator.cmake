# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

# TestGenerator.cmake:                      Contains some utils to generate 
#                                           test for the targets.
function(RR_GenerateTest tests link_with)
    list(LENGTH link_with link_with_length)
    list(LENGTH tests tests_length)
    math(EXPR test_length "${tests_length} - 1")
    foreach(index RANGE 0 ${tests_length} 2)
        # We need to get the pair of test elements from here, each test has
        # the [test_path, test_name], that is how the tests list is formatted.
        list(GET tests ${index} test_path)
        math(EXPR next_index "${index} + 1")
        list(GET tests ${next_index} test_name)

        # We add the executable:
        add_executable(${test_name} ${test_path})

        # We need to get everything we want linked into the executable.
        foreach(lw_index RANGE 0 ${link_with_length} 1)
            list(GET link_with ${lw_index} link_library)
            target_link_libraries({$test_name} PRIVATE ${link_library})
        endforeach()
        
        # Finally, this adds to the test.
        add_test(NAME ${test_name} COMMAND ${test_name})
    endforeach()
endfunction()