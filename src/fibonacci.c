//
// Created by Alan Stewart on 21/02/2016.
//
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

uint64_t fib_rec(int n, uint64_t a, uint64_t b) {
    return n-- > 0 ? fib_rec(n, b, a + b) : a;
}

uint64_t fib(int n) {
    return fib_rec(n, 0, 1);
}

int main(int argc, char *argv[])
{
    for (int n = 0; n <= 35; n++) {
        printf("%d:\t%llu\n", n, fib(n));
    }
    return EXIT_SUCCESS;
}

