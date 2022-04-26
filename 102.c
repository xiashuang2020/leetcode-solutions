//
// Created by pyxisha on 2021/5/5.
//

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

int** levelOrder(struct treeNode* root, int* returnSize, int** returnColumnSizes) {
    int **level;
    struct treeNode **currQ = NULL, **nextQ = NULL, *curr = NULL, **tmp;
    int currQi = 0, currQe = 0, nextQe = 0, leveli = 0;
    int level_num = 0;

    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    level = calloc(2000 * sizeof(int *), 1);
    currQ = calloc(2000 * sizeof(struct treeNode *), 1);
    nextQ = calloc(2000 * sizeof(struct treeNode *), 1);
    *returnColumnSizes = calloc(2000 * sizeof(int), 1);

    currQ[currQe++] = root;
    level[level_num] = calloc(1 * sizeof(int), 1);
    (*returnColumnSizes)[level_num] = currQe;

    while(currQi < currQe) {
        curr = currQ[currQi++];
        level[level_num][leveli++] = curr->val;

        if (curr->left)
            nextQ[nextQe++] = curr->left;
        if (curr->right)
            nextQ[nextQe++] = curr->right;

        if (currQi == currQe) {
            tmp = currQ;
            currQ = nextQ;
            nextQ = tmp;
            currQi = 0;
            currQe = nextQe;
            nextQe = 0;
            level_num++;
            leveli = 0;
            level[level_num] = calloc(1000 * sizeof(int), 1);
            (*returnColumnSizes)[level_num] = currQe;
        }
    }

    *returnSize = level_num;
    return level;
}
