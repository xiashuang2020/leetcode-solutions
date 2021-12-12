//
// Created by pyxisha on 2021/6/6.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static inline void traverse(struct TreeNode **prev, struct TreeNode *curr, struct TreeNode **first, struct TreeNode **second) {
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


void recoverTree(struct TreeNode* root) {
    struct TreeNode *prev = NULL, *first = NULL, *second = NULL;
    struct TreeNode *curr = root;

    loop:
    while (curr) {
        if (curr->left) {
            struct TreeNode *left_rmost = curr->left;
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

struct TreeNode node1 = {1, NULL, NULL};
struct TreeNode node3 = {2, NULL, NULL};
struct TreeNode node2 = {4, &node3, NULL};
struct TreeNode root = {3, &node1, &node2};

int main(void)
{
    recoverTree(&root);
    return 0;
}
