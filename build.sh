#!/bin/sh

# Ruka Raposa Project by Ruka Raposa Team & Contribuitors.
# Project is under GPL3-license, read LICENSE.md on the root.

RR_TestBuildFolder(){
    if [[ -d './Build' ]]; then
        return
    else
        mkdir ./Build
    fi
}

RR_RunCMAKEToConstructDebugVersion(){
    # This will enter the ./Build directory, make sure it is there:
    cd ./Build
        cmake                                       \
            -G Ninja                                \
            ..                                      \
            -DCMAKE_BUILD_TYPE="Debug"              \
            -DRR_ENABLE_ASAN=true                   \
            -DRR_ENABLE_TESTS=true
            # --debug-find                            \
            # --trace-expand
        [[ $? -eq 0 ]] && cmake --build . -v -j10
        [[ $? -eq 0 ]] && ctest . --extra-verbose --stop-on-failure --progress
    cd ..
}

RR_Main(){
    RR_TestBuildFolder
    RR_RunCMAKEToConstructDebugVersion
}
RR_Main;