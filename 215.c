//
// Created by xiash on 2022/3/31.
//

#define SWAP(a, b) {int tmp = (a); (a) = (b); (b) = (tmp);}

int findKthLargest(int* nums, int numsSize, int k) {
    if (numsSize < k)
        return -1;

    if (numsSize == 1) {
        return nums[0];
    } else if (numsSize == 2) {
        int min = nums[0] < nums[1] ? nums[0] : nums[1];
        int max = nums[0] > nums[1] ? nums[0] : nums[1];

        return k == 1 ? max : min;
    }

    int mid = nums[numsSize / 2];
    SWAP(nums[0], nums[numsSize / 2])

    int i = 1;
    int j = numsSize - 1;
    int t = 0;

    while (i <= j) {
        if (nums[i] < mid) {
            SWAP(nums[i], nums[t]);
            i++;
            t++;
        } else if (nums[i] == mid) {
            i++;
        } else if (nums[i] > mid) {
            if (nums[j] <= mid) {
                SWAP(nums[i], nums[j]);
                j--;
            } else {
                j--;
            }
        }
    }

    int num_mid = i - t;
    int num_large_mid = numsSize - i;
    int num_less_mid = t;

    if (k <= num_large_mid) {
        return findKthLargest(nums + i, num_large_mid, k);
    } else if (k > num_large_mid && k <= num_large_mid + num_mid) {
        return mid;
    } else {
        return findKthLargest(nums, num_less_mid, k - num_mid - num_large_mid);
    }
}

#include <stdio.h>
int main(void)
{
    int test1[2] = {2, 1};
    int test2[6] = {3, 2, 1, 5, 6, 4};
    int test3[9] = {3,2,3,1,2,4,5,5,6};
    printf("%d\n", findKthLargest(test1, 2, 1));
    printf("%d\n", findKthLargest(test1, 2, 2));
    printf("%d\n", findKthLargest(test2, 6, 2));
    printf("%d\n", findKthLargest(test2, 6, 1));
    printf("%d\n", findKthLargest(test2, 6, 3));
    printf("%d\n", findKthLargest(test2, 6, 4));
    printf("%d\n", findKthLargest(test2, 6, 5));
    printf("%d\n", findKthLargest(test2, 6, 6));
    printf("%d\n", findKthLargest(test3, 9, 1));
    printf("%d\n", findKthLargest(test3, 9, 2));
    printf("%d\n", findKthLargest(test3, 9, 4));
    printf("%d\n", findKthLargest(test3, 9, 7));
    printf("%d\n", findKthLargest(test3, 9, 8));
    printf("%d\n", findKthLargest(test3, 9, 9));

    return 0;
}