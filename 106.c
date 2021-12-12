//
// Created by pyxisha on 2021/8/22.
//

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* 分而治之 */

struct TreeNode nodes[3000];
int nodeIdx = 0;

struct TreeNode* buildTree_r(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    struct TreeNode* root;
    int root_val;
    int i;

    if (postorderSize == 0)
        return NULL;

    root_val = postorder[postorderSize - 1];
    root = &nodes[nodeIdx++];
    root->val = root_val;

    for (i = 0; i < inorderSize; ++i) {
        if (inorder[i] == root_val)
            break;
    }

    root->left = buildTree_r(inorder, i, postorder, i);
    root->right = buildTree_r(inorder + i + 1, inorderSize - i - 1, postorder + i, postorderSize - i - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    nodeIdx = 0;
    return buildTree_r(inorder, inorderSize, postorder, postorderSize);
}
