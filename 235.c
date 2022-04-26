//
// Created by pyxisha on 2022/4/14.
//

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

#include <stdio.h>

struct treeNode* lowestCommonAncestor(struct treeNode* root, struct treeNode* p, struct treeNode* q) {
    struct treeNode *curr = root;
    struct treeNode *next1, *next2;

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