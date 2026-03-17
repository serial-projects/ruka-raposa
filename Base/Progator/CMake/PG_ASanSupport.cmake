# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

# ASanSupport.cmake:                    An interface for the ASan builds during
#                                       development. Pretty useful for `NK`
#                                       or anything that deals with memory 
#                                       allocation.
add_library(PG_ASanSupportInterface INTERFACE)
if(PG_ENABLE_ASAN)
    if(MSVC)
        target_compile_options(PG_ASanSupportInterface INTERFACE
            $<$<CONFIG:Debug>:/fsanitize=address /Zi>
        )
        target_link_options(PG_ASanSupportInterface INTERFACE
            $<$<CONFIG:Debug>:/incremental:no>
        )
    else()
        target_compile_options(PG_ASanSupportInterface INTERFACE
            $<$<CONFIG:Debug>:-fsanitize=address -fno-omit-frame-pointer>
        )
        target_link_options(PG_ASanSupportInterface INTERFACE
            $<$<CONFIG:Debug>:-fsanitize=address>
        )
    endif()
endif()