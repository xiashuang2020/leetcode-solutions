//
// Created by pyxisha on 2021/6/13.
//

#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

static int cmp(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    return num1 - num2;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize){
    int i = 0;
    int j = 0;
    int min = 0;

    qsort(houses, housesSize, sizeof(int), cmp);
    qsort(heaters, heatersSize, sizeof(int), cmp);

    for (i = 0; i < housesSize; i++) {
        int hmin;
        while (j < heatersSize && heaters[j] < houses[i]) j++;

        if (j == 0)
            min = MAX(min, heaters[j] - houses[i]);
        else if (j == heatersSize)
            min = MAX(min, houses[i] - heaters[j - 1]);
        else
            min = MAX(min, MIN(heaters[j] - houses[i], houses[i] - heaters[j - 1]));
    }

    return min;
}

/*
[282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923]
[823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612]
 */