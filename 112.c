//
// Created by pyxisha on 2021/5/6.
//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* 非递归实现深度优先搜索 */

#define LEFT 0
#define RIGHT 1

struct pair {
    struct TreeNode *node;
    int path;
};

bool hasPathSum(struct TreeNode* root, int targetSum) {
    struct TreeNode *curr;
    int sum = 0;
    struct pair *list;
    int idx = -1;
    int next = LEFT;

    if (root == NULL)
        return false;

    list = calloc(5000 * sizeof(struct pair), 1);

    curr = root;
    list[++idx].node = curr;
    list[idx].path = RIGHT;
    while (curr != NULL) {
        sum += curr->val;
        if (curr->left == NULL && curr->right == NULL && sum == targetSum)
        {
            free(list);
            return true;
        } else if (curr->left && next <= LEFT) {
            curr = curr->left;
            list[++idx].node = curr;
            list[idx].path = LEFT;
            next = LEFT;
        } else if (curr->right && next <= RIGHT) {
            curr = curr->right;
            list[++idx].node = curr;
            list[idx].path = RIGHT;
            next = LEFT;
        } else {
            if (idx > 0) {
                sum -= curr->val;
                next = list[idx].path + 1;
                curr = list[--idx].node;
                sum -= curr->val;
            } else {
                curr = NULL;
            }
        }
    }

    return false;
}

struct TreeNode node5 = {2, NULL, NULL};
struct TreeNode node4 = {7, NULL, NULL};
struct TreeNode node3 = {11, &node4, &node5};
struct TreeNode node2 = {4, &node3, NULL};
struct TreeNode node1 = {5, &node2, NULL};

int main(void)
{
    hasPathSum(&node1, 22);
}