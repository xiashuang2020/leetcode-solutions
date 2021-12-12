//
// Created by pyxisha on 2021/4/18.
//

#include <stdio.h>

int hammingWeight(unsigned int n) {
    int ret = 0;
    unsigned int foo = n;

    __asm__ volatile (
            "popcnt %[val], %[ret]\n"
            : [ret] "=r" (ret)
            : [val] "m" (foo)
            : "memory"
            );

    return ret;
}

int main(void) {
    printf("%d\n", hammingWeight(0x1111));
}