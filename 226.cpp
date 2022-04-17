//
// Created by pyxisha on 2022/4/12.
//


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


#include <stdio.h>

struct TreeNode* invertTree(struct TreeNode* root) {
    if (!root)
        return NULL;

    struct TreeNode *left = root->left;
    struct TreeNode *right = root->right;
    root->left = right;
    root->right = left;
    invertTree(left);
    invertTree(right);

    return root;
}