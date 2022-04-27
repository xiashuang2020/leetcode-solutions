//
// Created by xiash on 2022/4/27.
//

int findDuplicate(int *nums, int numSize)
{
    int slow = nums[0];
    int fast = nums[nums[0]];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    fast = 0;
    while (slow != fast) {
        fast = nums[fast];
        slow = nums[slow];
    }

    return slow;
}


#include <stdio.h>
int main(void)
{
    int test1[5] = {1, 3, 4, 2, 2};
    printf("%d\n", findDuplicate(test1, 5));
    int test2[5] = {3, 1, 3, 4, 2};
    printf("%d\n", findDuplicate(test2, 5));
}