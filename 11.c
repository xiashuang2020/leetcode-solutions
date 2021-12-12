//
// Created by pyxisha on 2021/4/6.
//

/* 关键点， 双指针遍历 */

#include <stdio.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize){
    int i = 0;
    int j = heightSize - 1;
    int max = 0, s;

    if (heightSize < 2)
        return 0;

    while (i < j)
    {
        s = min(height[i], height[j]) * (j - i);
        if (s > max)
            max = s;

        if (height[i] < height[j])
            i++;
        else
            j--;
    }

    return max;
}

int main(void)
{
    int arr[10] = {1,8,6,2,5,4,8,3,7};

    printf("%d\n", maxArea(arr, 9));
}