# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

# ASanSupport.cmake:                    An interface for the ASan builds during
#                                       development. Pretty useful for `NK`
#                                       or anything that deals with memory 
#                                       allocation.
add_library(RR_ASanSupportInterface INTERFACE)
if(DEFINED RR_ENABLE_ASAN_SUPPORT)
    if(MSVC)
        target_compile_options(RR_ASanSupportInterface INTERFACE
            $<$<CONFIG:Debug>:/fsanitize=address /Zi>
        )
        target_link_options(RR_ASanSupportInterface INTERFACE
            $<$<CONFIG:Debug>:/incremental:no>
        )
    else()
        target_compile_options(RR_ASanSupportInterface INTERFACE
            $<$<CONFIG:Debug>:-fsanitize=address -fno-omit-frame-pointer>
        )
        target_link_options(RR_ASanSupportInterface INTERFACE
            $<$<CONFIG:Debug>:-fsanitize=address>
        )
    endif()
endif()