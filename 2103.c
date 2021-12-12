//
// Created by pyxisha on 2021/12/12.
//

#include <strings.h>
#include <stdio.h>



int countPoints(char * rings) {
    int rod[10] = {0};
    int total = 0;

    char *s = rings;
    while (*s) {
        int v;

        if (*s == 'R')
            v = 1;
        else if (*s == 'G')
            v = 2;
        else
            v = 4;

        s++;
        rod[*s - '0'] |= v;
        s++;
    }

    for (int i = 0; i < 10; ++i) {
        if (rod[i] == 7) {
            total += 1;
        }
    }

    return total;
}


int main(void) {
    printf("%d\n", countPoints("B0R0G0R9R0B0G0"));
    printf("%d\n", countPoints("G4"));
}