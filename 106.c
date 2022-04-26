//
// Created by pyxisha on 2021/8/22.
//

#include <stdio.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

/* 分而治之 */

struct treeNode nodes[3000];
int nodeIdx = 0;

struct treeNode* buildTree_r(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    struct treeNode* root;
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

struct treeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    nodeIdx = 0;
    return buildTree_r(inorder, inorderSize, postorder, postorderSize);
}
