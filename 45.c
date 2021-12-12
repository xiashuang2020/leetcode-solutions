//
// Created by pyxisha on 2021/5/3.
//

#include <stdbool.h>
#include <stdio.h>

/* 贪心算法
 * 如果能到达k+1, 必然能到k
 * 记录下上一轮所能达到最大的位置以及起点
 * */

int jump(int* nums, int numsSize) {
    int last = 0;
    int max = nums[0];
    int new_max;
    int new_last;
    int step = 1;

    if (numsSize == 1)
        return 0;

    while (max < numsSize - 1) {
        new_max = 0;
        for (int i = last + 1; i <= max; ++i) {
            if (i + nums[i] > new_max) {
                new_max = i + nums[i];
                new_last = i;
            }
        }

        max = new_max;
        last = new_last;
        step++;
    }

    return step;
}
