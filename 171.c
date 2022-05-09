//
// Created by pyxisha on 2022/5/2.
//


#include <string.h>
#include <stdio.h>


int titleToNumber(char * columnTitle)
{
    int n = strlen(columnTitle);
    long pow = 1;
    int ret = 0;
    for (int i = n - 1; i >= 0; i--) {
        ret += (columnTitle[i] - 'A'  + 1) * pow;
        pow *= 26;
    }

    return ret;
}

int main(void) {
    printf("%d\n", titleToNumber("B"));
    printf("%d\n", titleToNumber("AA"));
    printf("%d\n", titleToNumber("ZY"));
}