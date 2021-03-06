//
// Created by pyxisha on 2021/4/15.
//

#include <stdio.h>
#include <stdlib.h>

/* 非递归无额外空间遍历
 * 1. rightmost->right = curr
 * 2. rm->right == curr, rm->right == NULL
 * */

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct treeNode* root, int* returnSize) {
    int *ret = NULL;
    int r_size = 0;
    struct treeNode *curr = NULL, *rm = NULL;


    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    ret = calloc(100 * sizeof(int), 1);
    if (!ret) {
        return NULL;
    }

    curr = root;
    loop:
    while (curr) {
        if (curr->left) {
            rm = curr->left;
            while (rm->right) {
                if (rm->right == curr) {
                    rm->right = NULL;
                    ret[r_size++] = curr->val;
                    curr = curr->right;
                    goto loop;
                }
                rm = rm->right;

            }
            rm->right = curr;
            curr = curr->left;
        } else {
            ret[r_size++] = curr->val;
            curr = curr->right;
        }
    }

    *returnSize = r_size;
    return ret;
}

struct treeNode node3 = {3, NULL, NULL};
struct treeNode node2 = {2, &node3, NULL};
struct treeNode node1 = {1, NULL, &node2};

int main(void)
{
    int size;
    int *ret = inorderTraversal(&node1, &size);

    return 0;
}