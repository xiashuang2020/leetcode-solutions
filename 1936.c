//
// Created by pyxisha on 2021/7/18.
//


#include <stdio.h>

int addRungs(int* rungs, int rungsSize, int dist) {
    int cur_height = 0;
    int ret = 0;

    for (int i = 0; i < rungsSize; ++i) {
        int diff = rungs[i] - cur_height;
        int add = (diff - 1) / dist;
        ret += add;
        cur_height = rungs[i];
    }

    return ret;
}


int main(void)
{
    int rungs1[4] = {1, 3, 5, 10};
    int rungs2[4] = {3, 6, 8, 10};

    printf("%d\n", addRungs(rungs1, 4, 2));
    printf("%d\n", addRungs(rungs2, 4, 3));
}