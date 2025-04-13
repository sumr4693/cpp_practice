#!/bin/bash

mkdir -p ./build
{
    EXE=./build/$1
    EXE_DBG=./build/$1_dbg
    g++ --std=c++17 -O2 $1.cpp -o $EXE
    g++ --std=c++17 -g $1.cpp -o $EXE_DBG
    ./${EXE}
}