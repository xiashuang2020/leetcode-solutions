//
// Created by pyxisha on 2022/4/25.
//

#include <stdio.h>

int addDigits(int num){
    if (num == 0)
        return 0;
    int ret = num % 9;
    return ret != 0 ? ret : 9;
}

int main(void)
{
    printf("%d\n", addDigits(123));
}