//
// Created by pyxisha on 2022/4/11.
//

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



bool isPowerOfTwo(int n){
    return hammingWeight(n) == 1;
}