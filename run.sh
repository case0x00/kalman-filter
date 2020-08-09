#!/bin/bash

build(){
    rm -rf build/
    mkdir build
    cd build
    cmake ..
    make -j4
}

if [[ $1 == "--build" ]]; then
    build
elif [[ $1 == "--run" ]]; then
    ./build/kalmanfilter
else
    build
    ./kalmanfilter
fi
