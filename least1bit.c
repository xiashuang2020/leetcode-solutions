//
// Created by pyxisha on 2021/4/4.
//

#include <stdio.h>


int bsr(unsigned long num) {
    unsigned long ret;

    asm volatile ("bsfq %1, %0":"=r"(ret):"m"(num): "cc", "memory");

    return (int)ret;
}



int main(void)
{
    unsigned long foo = 1UL << 45;

    printf("%d\n", bsr(foo));
}