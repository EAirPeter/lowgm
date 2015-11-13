#!/bin/sh
[ -e test.out ] && rm -f test.out
gcc -g -std=c11 -Wall -Wconversion -Werror -Wextra -Wformat -o test.out test.c ../src/*.c
[ -e test.out ] && gdb test.out
