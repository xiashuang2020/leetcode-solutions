//
// Created by pyxisha on 2021/7/18.
//



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

struct node {
    struct node *parent;
    int v;
};

int* maxGeneticDifference(int* parents, int parentsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    struct node *tree = calloc(parentsSize * sizeof(struct node), 1);
    int *ret = calloc(queriesSize * sizeof(int), 1);

    for (int i = 0; i < parentsSize; ++i) {
        if (parents[i] != -1)
            tree[i].parent = tree + parents[i];
        else
            tree[i].parent = NULL;
        tree[i].v = i;
    }

    for (int i = 0; i < queriesSize; ++i) {
        int xor = queries[i][1];
        int m = 0;
        struct node *node = tree + queries[i][0];
        while (node) {
            m = (node->v ^ xor) > m ? node->v ^ xor : m;
            node = node->parent;
        }

        ret[i] = m;
    }

    *returnSize = queriesSize;
    free(tree);
    return ret;
}

int main(void)
{
    int parents[4] = {-1, 0, 1, 1};
    int q1[2] = {0, 2};
    int q2[2] = {3, 2};
    int q3[2] = {2, 5};
    int *querys[3] = {q1, q2, q3};
    int ret_size;

    int *ret = maxGeneticDifference(parents, 4, querys, 3, NULL, &ret_size);
    return 0;
}