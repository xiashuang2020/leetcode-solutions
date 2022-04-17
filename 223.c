//
// Created by pyxisha on 2022/4/14.
//

#include <stdbool.h>
#include <stdio.h>

#define MIN(a, b) (a) < (b) ? (a) : (b)
#define MAX(a, b) (a) > (b) ? (a) : (b)

static inline bool intersect(int x1, int x2, int x3, int x4)
{
    return !((x2 <= x3) || (x1 >= x4));
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2){
    int area1 = (ax2 - ax1) * (ay2 - ay1);
    int area2 = (bx2 - bx1) * (by2 - by1);

    if (intersect(ax1, ax2, bx1, bx2) && intersect(ay1, ay2, by1, by2)) {
        int cx1, cx2, cy1, cy2;
        cx1 = MAX(ax1, bx1);
        cx2 = MIN(ax2, bx2);
        cy1 = MAX(ay1, by1);
        cy2 = MIN(ay2, by2);
        int area3 = (cx2 - cx1) * (cy2 - cy1);


        return area1 + area2 - area3;
    } else {
        return area1 + area2;
    }
}

int main(void)
{
    printf("%d\n", computeArea(-3, 0, 3, 4, 0, -1, 9, 2));
}