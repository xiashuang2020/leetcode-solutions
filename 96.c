//
// Created by pyxisha on 2021/4/16.
//

#include <stdio.h>

/* 选定一个头，分而治之 */

int numTrees(int n) {
    int cons[20] = {0};
    int i, c, j;

    cons[0] = 1;
    cons[1] = 1;

    for (i = 2; i <= n; i++) {
        c = 0;
        for (j = 1; j <= i; j++) {
            c += cons[j - 1] * cons[i - j];
        }
        cons[i] = c;
    }

    return cons[n];
}

int main(void) {
    printf("%d\n", numTrees(1));
    printf("%d\n", numTrees(2));
    printf("%d\n", numTrees(3));
}