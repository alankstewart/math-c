//
// Created by Alan Stewart on 21/02/2016.
//
#include <stdio.h>
#include <stdlib.h>

long long fib_rec(int n, long long a, long long b) {
    return n-- > 0 ? fib_rec(n, b, a + b) : a;
}

long long fib(int n) {
    return fib_rec(n, 0, 1);
}

int main(int argc, char *argv[])
{
    for (int n = 0; n <= 35; n++) {
        printf("%d:\t%lld\n", n, fib(n));
    }
    return EXIT_SUCCESS;
}

