//
// Created by pyxisha on 2021/5/5.
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

static void __buildTree(struct TreeNode** root, int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    int pre, i;

    pre = preorder[0];
    *root = &nodes[nodeIdx++];
    (*root)->val = pre;

    for (i = 0; i < inorderSize; ++i) {
        if (inorder[i] == pre)
            break;
    }

    if (i > 0) {
        __buildTree(&(*root)->left, preorder + 1, i, inorder, i);
    } else {
        (*root)->left = NULL;
    }

    if (i < preorderSize - 1) {
        __buildTree(&(*root)->right, preorder + i + 1, preorderSize - i - 1, inorder + i + 1, inorderSize - i - 1);
    } else {
        (*root)->right = NULL;
    }


}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode *root = NULL;

    nodeIdx = 0;
    __buildTree(&root, preorder, preorderSize, inorder, inorderSize);

    return root;
}