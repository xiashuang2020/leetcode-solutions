//
// Created by pyxisha on 2022/4/12.
//


struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};


#include <stdio.h>

struct treeNode* invertTree(struct treeNode* root) {
    if (!root)
        return NULL;

    struct treeNode *left = root->left;
    struct treeNode *right = root->right;
    root->left = right;
    root->right = left;
    invertTree(left);
    invertTree(right);

    return root;
}