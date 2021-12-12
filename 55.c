//
// Created by pyxisha on 2021/5/3.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool canJump2(int* nums, int numsSize) {
    int *map = NULL;

    map = calloc(numsSize * sizeof(int), 1);
    map[0] = 1;

    for (int i = 0; i < numsSize; ++i) {
        if (map[i] == 1) {
            for (int j = 0; j < nums[i]; ++j) {
                if (i + j < numsSize)
                    map[i + j] = 1;
            }
        }
    }

    return map[numsSize - 1] == 1 ? true : false;
}

bool canJump(int* nums, int numsSize) {
    int last = 0;
    int max = nums[0];
    int new_max;
    int new_last;

    while (max > last) {
        if (max >= numsSize - 1)
            return true;

        new_max = 0;
        for (int i = last + 1; i <= max; ++i) {
            if (i + nums[i] > new_max) {
                new_max = i + nums[i];
                new_last = i;
            }
        }

        max = new_max;
        last = new_last;
    }

    return max >= numsSize - 1;
}

int main(void) {
    int arr[5] = {3,2,1,0,4};
    printf("%d\n", canJump(arr, 5));
}