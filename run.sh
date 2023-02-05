#!/bin/sh

echo "compiling game..."
g++ main.cpp -o game.bin -lGL -lglut -lGLU
if [ $? = 1 ]; then
    echo -e "\e[1;31m\033[1mFailed\033[0m"
    exit 1
else
    echo "finished compiling"
    sleep 0.5s
    echo "running..."
    sleep 0.5s
    ./game.bin
    echo "done"
    exit 0
fi