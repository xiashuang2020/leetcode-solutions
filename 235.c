//
// Created by pyxisha on 2022/4/14.
//

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#include <stdio.h>

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *curr = root;
    struct TreeNode *next1, *next2;

    while (curr) {
        if (p->val < curr->val) {
            next1 = curr->left;
        } else if (p->val > curr->val) {
            next1 = curr->right;
        } else {
            next1 = curr;
        }

        if (q->val < curr->val) {
            next2 = curr->left;
        } else if (q->val > curr->val) {
            next2 = curr->right;
        } else {
            next2 = curr;
        }

        if (next1 != next2 || next1 == curr)
            return curr;

        curr = next1;
    }

    return NULL;
}