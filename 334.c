//
// Created by xiash on 2022/5/7.
//

#include <stdbool.h>
#include <stdio.h>

bool increasingTriplet(int *nums, int numsSize)
{
    int i = 0, j = 1, k = 2;

    while (k < numsSize) {
        if (nums[j] <= nums[i]) {
            i++;
            j++;
            k++;
            continue;
        }
        if (nums[k] > nums[j]) {
            return true;
        } else if (nums[k] > nums[i]) {
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
                k = j + 1;
                //printf("%d %d %d\n", i, j, k);
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
    int test4[6] = {1, 5, 0, 4, 1, 3};

    printf("%d\n", increasingTriplet(test1, 5));
    printf("%d\n", increasingTriplet(test2, 5));
    printf("%d\n", increasingTriplet(test2, 4));
    printf("%d\n", increasingTriplet(test4, 6));
}