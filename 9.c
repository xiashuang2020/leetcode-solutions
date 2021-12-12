//
// Created by pyxisha on 2021/5/23.
//

#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
    int foo[12] = {0};
    int i = 0, j = 0;

    if (x < 0)
        return false;

    while (x > 0) {
        foo[i] = x % 10;
        x = x / 10;
        i++;
    }

    for (j = 0; j < i / 2; j++) {
        if (foo[j] != foo[i - j - 1])
            return false;
    }

    return true;
}

int main(void)
{
    printf("%d", isPalindrome(121));
    printf("%d", isPalindrome(12));
}