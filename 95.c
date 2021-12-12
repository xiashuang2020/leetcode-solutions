//
// Created by pyxisha on 2021/4/18.
//

#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int numTrees(int n) {
    int cons[20] = {0};
    int i, c, j;

    cons[0] = 1;
    cons[1] = 1;

    for (i = 2; i <= n; i++) {
        c = 0;
        for (j = 1; j <= i; j++) {
            c += cons[j - 1] * cons[i - j];
        }
        cons[i] = c;
    }

    return cons[n];
}

struct TreeNode** __generateTrees(int n, int* returnSize, int lo) {
    int left_size;
    int right_size;
    struct TreeNode **left;
    struct TreeNode **right;
    struct TreeNode **ret;
    int r = 0;

    if (n == 0) {
        *returnSize = 1;
        ret = calloc(sizeof(struct TreeNode *) * 1, 1);
        ret[0] = NULL;
        return ret;
    } else {
        *returnSize = numTrees(n);
        ret = calloc(sizeof(struct TreeNode *) * (*returnSize), 1);
    }

    for (int i = 0; i < n; ++i) {
        left = __generateTrees(i, &left_size, lo);
        right = __generateTrees(n - i - 1, &right_size, lo + i + 1);

        for (int j = 0; j < left_size; ++j) {
            for (int k = 0; k < right_size; ++k) {
                struct TreeNode *new = calloc(sizeof(struct TreeNode), 1);
                new->val = lo + i;
                new->left = left[j];
                new->right = right[k];
                ret[r++] = new;
            }

        }
    }

    return ret;
}

struct TreeNode** generateTrees(int n, int* returnSize)
{
    return __generateTrees(n, returnSize, 1);
}

int main(void)
{
    int size;
    struct TreeNode **ret = generateTrees(3, &size);

    return 0;
}