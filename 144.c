//
// Created by pyxisha on 2021/4/18.
//



struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *preorderTraversal(struct treeNode *root, int *returnSize) {
    struct treeNode *rm = NULL, *curr = NULL;
    int *ret = 0, r_size = 0;

    ret = malloc(100 * sizeof(int));
    if (ret == NULL) {
        *returnSize = 0;
        return NULL;
    }

    if (root == NULL) {
        *returnSize = 0;
        return ret;
    }

    curr = root;
    loop:
    while (curr) {
        if (curr->left) {
            rm = curr->left;
            while (rm->right) {
                if (rm->right == curr) {
                    curr = curr->right;
                    rm->right = NULL;
                    goto loop;
                }
                rm = rm->right;
            }
            rm->right = curr;
            ret[r_size++] = curr->val;
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
    int *ret = preorderTraversal(&node1, &size);

    return 0;
}