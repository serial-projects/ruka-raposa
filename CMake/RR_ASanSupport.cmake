# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

add_library(RR_ASanSupportInterface INTERFACE)
if(RR_ENABLE_ASAN)
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