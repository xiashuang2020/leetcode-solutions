//
// Created by pyxisha on 2022/2/22.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int *ret;
    ret = malloc(sizeof(int) * 2);

    *returnSize = 2;
    int i = 0;
    int j = numbersSize - 1;

    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum > target)
            j--;
        else if (sum < target) {
            i++;
        } else {
            ret[0] = i + 1;
            ret[1] = j + 1;
            return ret;
        }
    }

    return ret;
}

int main(void)
{
    int test1[4] = {2, 7, 11, 15};

    printf("%d\n", )
}