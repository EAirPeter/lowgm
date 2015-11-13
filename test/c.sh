#!/bin/sh
[ -e test.out ] && rm -f test.out
gcc -std=c11 -Wall -Wconversion -Werror -Wextra -Wformat -o test.out test.c ../src/*.c
[ -e test.out ] && valgrind --track-fds=yes --leak-check=full --undef-value-errors=yes ./test.out
