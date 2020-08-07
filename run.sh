#!/bin/bash

rm -rf build/
mkdir build
cd build
cmake ..
make -j4

if [ $? -eq 0 ]; then
    ./kalmanfilter
fi
