#!/bin/sh

echo Compiling $1
gcc -ansi -pedantic-errors -Wall -c "$1".c
gcc -o "$1" "$1".o
