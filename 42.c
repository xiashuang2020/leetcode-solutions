//
// Created by pyxisha on 2021/4/28.
//

/* 记录下highestToend
 * 如果后面还有>=自己的，则找大于等于自己的
 * 否则找最大的
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int trap(int* height, int heightSize){
    int *highest = NULL;
    int max;
    int i = 0, j, k, left;
    int ret = 0;

    if (heightSize == 0)
        return 0;

    highest = calloc(sizeof(int) * heightSize, 1);
    max = height[heightSize - 1];
    for (j = heightSize - 1; j >= 0; j--) {
        if (height[j] > max)
            max = height[j];

        highest[j] = max;
    }

    while(i < heightSize && height[i] == 0)
        i++;

    left = i;
    while (left < heightSize - 1) {
        i++;
        if (highest[left + 1] < height[left]) {
            while (height[i] != highest[left + 1])
                i++;
        } else {
            while(height[i] < height[left])
                i++;
        }
        ret += MIN(height[i], height[left]) * (i - left - 1);
        for (k = left + 1; k < i; k++)
            ret -= height[k];
        left = i;
    }

    return ret;
}

int main(void)
{

    int height[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int height2[6] = {4,2,0,3,2,5};
    printf("%d\n", trap(height, 12));
    printf("%d\n", trap(height2, 6));
}