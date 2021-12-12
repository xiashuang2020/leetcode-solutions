//
// Created by pyxisha on 2021/5/2.
//

#include <stdio.h>

/* 以0分界讨论
 * 奇数个负数和偶数个负数的情况分开讨论
 */

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int maxProductNoZero(int *nums, int numsSize)
{
    int numNegative = 0;
    int first = -1;
    int last = -1;
    int i;
    int product = 1;
    int product2 = 1;

    if (numsSize == 1)
        return nums[0];

    for (i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            numNegative += 1;
            last = i;
            if (first < 0)
                first = i;
        }
    }

    if (numNegative % 2 == 0) {
        for (i = 0; i < numsSize; i++)
        {
            product *= nums[i];
        }
        return product;
    } else {
        for (i = first + 1; i < numsSize; i++) {
            product *= nums[i];
        }

        for (i = last - 1; i >= 0; i--) {
            product2 *= nums[i];
        }
        return MAX(product, product2);
    }
}

int maxProduct(int* nums, int numsSize) {
    int max = 0x80000000;
    int array_start = 0;
    int array_size = 0;
    int i = 0;

    while (i < numsSize) {
        if (nums[i] != 0) {
            array_size++;
        } else {
            max = MAX(max, 0);
            if (array_size != 0)
                max = MAX(max, maxProductNoZero(nums + array_start, array_size));
            array_start = i + 1;
            array_size = 0;
        }

        i++;
    }

    if (array_size > 0)
        max = MAX(max, maxProductNoZero(nums + array_start, array_size));

    return max;
}

int main(void)
{

    int array[10] = {1, 2, 3, 0, 4, 5};

    printf("%d\n", maxProduct(array, 6));
}