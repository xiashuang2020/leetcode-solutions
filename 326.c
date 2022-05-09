//
// Created by xiash on 2022/5/7.
//

#include <stdbool.h>
#include <stdio.h>

bool isPowerOfThree(int n) {
    if (n <= 0)
        return false;

    while (n > 1) {
        if (n % 3 == 0)
            n = n / 3;
        else
            return false;
    }

    return true;
}

int main(void)
{
    printf("%d\n", isPowerOfThree(1));
    printf("%d\n", isPowerOfThree(2));
    printf("%d\n", isPowerOfThree(3));
    printf("%d\n", isPowerOfThree(27));
    printf("%d\n", isPowerOfThree(28));
}