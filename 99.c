//
// Created by pyxisha on 2021/6/6.
//

/**
 * Definition for a binary tree node.
 * struct treeNode {
 *     int val;
 *     struct treeNode *left;
 *     struct treeNode *right;
 * };
 */

#include <stdio.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

static inline void traverse(struct treeNode **prev, struct treeNode *curr, struct treeNode **first, struct treeNode **second) {
    if (*prev != NULL && (*prev)->val > curr->val) {
        if (*first == NULL) {
            *first = *prev;
            *second = curr;
        } else {
            *second = curr;
        }
    }

    *prev = curr;
}


void recoverTree(struct treeNode* root) {
    struct treeNode *prev = NULL, *first = NULL, *second = NULL;
    struct treeNode *curr = root;

    loop:
    while (curr) {
        if (curr->left) {
            struct treeNode *left_rmost = curr->left;
            while (left_rmost->right) {
                if (left_rmost->right != curr)
                {
                    left_rmost = left_rmost->right;
                } else {
                    traverse(&prev, curr, &first, &second);
                    curr = left_rmost->right->right;
                    left_rmost->right = NULL;
                    goto loop;
                }
            }
            left_rmost->right = curr;
            curr = curr->left;
            continue;
        }

        traverse(&prev, curr, &first, &second);
        curr = curr->right;
    }

    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
    return;
}

struct treeNode node1 = {1, NULL, NULL};
struct treeNode node3 = {2, NULL, NULL};
struct treeNode node2 = {4, &node3, NULL};
struct treeNode root = {3, &node1, &node2};

int main(void)
{
    recoverTree(&root);
    return 0;
}
