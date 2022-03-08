//
// Created by xiash on 2022/3/8.
//

#include <stdlib.h>
#include <stdio.h>

static inline int n_digits(int num)
{
    int ret = 0;

    if (num == 0)
        return 1;

    while (num > 0) {
        num /= 10;
        ret++;
    }

    return ret;
}

static inline int first_digit(int num, int n)
{
    while (n >1)
    {
        num /= 10;
        n--;
    }

    return num;
}

int pow_10(int n)
{
    int ret = 1;
    while (n) {
        ret *= 10;
        n--;
    }

    return ret;
}

static int cmp(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    int digits1 = n_digits(num1);
    int digits2 = n_digits(num2);
    long merge1 = (long)num1 * (long)pow_10(digits2) + (long)num2;
    long merge2 = (long)num2 * (long)pow_10(digits1) + (long)num1;

    return merge1 < merge2;
}

char * largestNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    char *ret = calloc(1, 2000);
    int j = 0;

    for (int i = 0; i < numsSize; ++i) {
        int num = nums[i];
        int digits = n_digits(num);
        while (digits > 0) {
            int digit = first_digit(num, digits);
            if (j != 0 || digit != 0 || i == numsSize - 1)
                ret[j++] = '0' + digit;
            num -= digit * pow_10(digits - 1);
            digits--;
        }
    }

    return ret;
}

int main(void)
{
    int test[5] = {30,3,34,5,9};
    int test2[2] = {10, 2};
    int test3[2] = {111311, 1113};
    int test4[1] = {2048};
    int test5[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int test6[2] = {0, 0};

    printf("%s\n", largestNumber(test, 5));
    printf("%s\n", largestNumber(test2, 2));
    printf("%s\n", largestNumber(test3, 2));
    printf("%s\n", largestNumber(test4, 1));
    printf("%s\n", largestNumber(test5, 10));
    printf("%s\n", largestNumber(test6, 2));
}