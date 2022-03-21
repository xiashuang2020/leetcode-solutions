//
// Created by xiash on 2022/3/16.
//


void reverse(int *nums, int s, int e)
{
    int i = s;
    int j = e;

    while (i < j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
}

void rotate(int* nums, int numsSize, int k){
    k = k % numsSize;
    if (k == 0)
        return;

    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);

    return;
}

#include <stdio.h>
int main(void)
{
    int test[7] = {1, 2, 3, 4, 5, 6, 7};

    rotate(test, 7, 3);
    for (int i = 0; i < 7; ++i) {
        printf("%d ", test[i]);
    }

    printf("\n");
}