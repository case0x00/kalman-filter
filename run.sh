#!/bin/bash

RED=$(printf '\033[31m')
RESET=$(printf '\033[m')

while getopts "t:n:" flag; do
    case "${flag}" in
        t)
            runtype=${OPTARG};;
        n)
            name=${OPTARG};;
    esac
done
shift $((OPTIND - 1))

build(){
    rm -rf build/
    mkdir build
    cd build
    cmake ..
    make -j4
}

main() {

    echo "${RED}built with <3 by @onlycase_${RESET}"

    if [[ $runtype == "gen" ]]; then
        echo "${RED}>${RESET} generating groundtruth and measurement files."
        cd tests
        python3 gen.py --gt > groundtruth.txt
        python3 gen.py --meas > measurement.txt
    elif [[ $runtype == "build" ]]; then
        build
    elif [[ $runtype == "run" ]]; then
        echo "${RED}>${RESET} plotting data."
        ./build/kalmanfilter tests/measurement.txt tests/groundtruth.txt | python3 ./tests/main.py $name 
    elif [[ $runtype == "all" ]]; then
        build
        ./kalmanfilter ../tests/measurement.txt ../tests/groundtruth.tt | python3 ../tests/main.py $name
    fi
}

main 
