//
// Created by pyxisha on 2021/12/12.
//

#include <string.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

static inline int can_reach(int s, int e, int pos, int k)
{
    if (e < pos) {
        return pos - k <= s;
    } else if (s > pos) {
        return pos + k >= e;
    }

    int left = pos - s;
    int right = e - pos;
    return left + right + MIN(left, right) <= k;
}

int maxTotalFruits(int** fruits, int fruitsSize, int* fruitsColSize, int startPos, int k)
{
    int min_idx = startPos - k;
    int max_idx = startPos + k;
    int ret = 0;
    int sum_fo_far = 0;

    int s_idx = -1;
    int e_idx = 0;

    while (e_idx < fruitsSize && s_idx <= e_idx)
    {
        if (fruits[e_idx][0] < min_idx) {
            e_idx++;
            continue;
        }
        else if (fruits[e_idx][0] > max_idx)
            break;

        if (s_idx == -1)
            s_idx = e_idx;

        if (can_reach(fruits[s_idx][0], fruits[e_idx][0], startPos, k)) {
            sum_fo_far += fruits[e_idx][1];
            e_idx++;
        } else {
            if (sum_fo_far > ret)
                ret = sum_fo_far;

            sum_fo_far -= fruits[s_idx][1];
            s_idx++;
        }
    }

    if (sum_fo_far > ret)
        ret = sum_fo_far;

    return ret;
}

#include <stdio.h>
int main(void)
{
    int apple1[2] = {2, 8};
    int apple2[2] = {6, 3};
    int apple3[2] = {8, 6};
    int *test1[3] = {apple1, apple2, apple3};
    printf("%d\n", maxTotalFruits(test1, 3, NULL, 5, 4));
    int apple4[2] = {0,9};
    int apple5[2] = {4,1};
    int apple6[2] = {5,7};
    int apple7[2] = {6,2};
    int apple8[2] = {7,4};
    int apple9[2] = {10,9};
    int *test2[6] = {apple4, apple5, apple6, apple7, apple8, apple9};
    printf("%d\n", maxTotalFruits(test2, 6, NULL, 5, 4));
    int apple10[2] = {0,3};
    int apple11[2] = {6,4};
    int apple12[2] = {8,5};
    int *test3[3] = {apple10, apple11, apple12};
    printf("%d\n", maxTotalFruits(test3, 3, NULL, 3, 2));
    int apple14[2] = {200000, 10000};
    int *test4[2] = {apple14};
    printf("%d\n", maxTotalFruits(test4, 1, NULL, 200000, 0));
}
