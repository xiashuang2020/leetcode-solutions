//
// Created by pyxisha on 2022/4/10.
//

#include <stdbool.h>
#include <stdio.h>

static inline bool intersect(int x1, int x2, int x3, int x4)
{
    return !((x2 <= x3) || (x1 >= x4));
}


bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    int x1 = rec1[0];
    int y1 = rec1[1];
    int x2 = rec1[2];
    int y2 = rec1[3];
    int x1x = rec2[0];
    int y1y = rec2[1];
    int x2x = rec2[2];
    int y2y = rec2[3];

    return intersect(x1, x2, x1x, x2x) && intersect(y1, y2, y1y, y2y);
}

int main(void)
{
    int test1[4] = {0,0,2,2};
    int test2[4] = {1,1,3,3};
    int test3[4] = {0,0,1,1};
    int test4[4] = {1,0,2,1};
    printf("%d\n", isRectangleOverlap(test1, 4, test2, 4));
    printf("%d\n", isRectangleOverlap(test3, 4, test4, 4));
}