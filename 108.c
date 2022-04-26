//
// Created by pyxisha on 2021/8/22.
//

#include <stdio.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};
int nodeIdx = 0;
struct treeNode node[10000];

struct treeNode* sorted_r(int* nums, int numsSize) {
    struct treeNode *root = NULL;
    int mid;

    if (numsSize == 0)
        return NULL;

    mid = numsSize / 2;
    root = &node[nodeIdx++];
    root->val = nums[mid];
    root->left = sorted_r(nums, mid);
    root->right = sorted_r(nums + mid + 1, numsSize - mid - 1);

    return root;
}

struct treeNode* sortedArrayToBST(int* nums, int numsSize) {
    nodeIdx = 0;
    return sorted_r(nums, numsSize);
}
