//
// Created by xiash on 2022/5/7.
//

#include <stdbool.h>
#include <stdio.h>

bool increasingTriplet(int *nums, int numsSize)
{
    int i = 0, j = 1, k = 2;

    while (k < numsSize) {
        if (nums[j + 1] <= nums[i]) {
            i++;
            j++;
            k++;
            continue;
        }
        if (nums[k] > nums[j]) {
            return true;
        } else if (nums[k] > nums[j]) {
            j = k;
            k++;
            continue;
        } else {
            int t = k + 1;
            if (t >= numsSize)
                return false;
            else if (nums[t] <= nums[k]) {
                k++;
                continue;
            } else if (nums[t] > nums[j]){
                return true;
            } else {
                i = k;
                j = t;
                k++;
                continue;
            }
        }

    }

    return false;
}

int main(void)
{
    int test1[5] = {5, 4, 3, 2 ,1};
    int test2[5] = {5, 6, 1, 2, 3};
    int test3[7] = {5, 6, 1, 2, 1, 2, 5};
    printf("%d\n", increasingTriplet(test1, 5));
    printf("%d\n", increasingTriplet(test2, 5));
    printf("%d\n", increasingTriplet(test2, 4));
    printf("%d\n", increasingTriplet(test3, 7));
}