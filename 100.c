//
// Created by pyxisha on 2021/5/2.
//

#include <stdbool.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static bool treeNodeEqual(struct TreeNode* node1, struct TreeNode* node2)
{
    if (node1->val != node2->val)
        return false;

    if (node1->left == NULL && node2->left != NULL)
        return false;

    if (node1->left != NULL && node2->left == NULL)
        return false;

    if (node1->right == NULL && node2->right != NULL)
        return false;

    if (node1->right != NULL && node2->right == NULL)
        return false;

    return true;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *Q1[100] = {0};
    struct TreeNode *Q2[100] = {0};
    int qs = 0,  qe = 0;
    struct TreeNode *t1 = NULL, *t2 = NULL;

    if (p == NULL && q == NULL)
        return true;

    if (p == NULL || q == NULL)
        return false;

    Q1[0] = p;
    Q2[0] = q;
    qe++;

    while (qs < qe) {
        t1 = Q1[qs];
        t2 = Q2[qs];
        qs++;

        if (!treeNodeEqual(t1, t2))
            return false;

        if (t1->left != NULL) {
            Q1[qe] = t1->left;
            Q2[qe] = t2->left;
            qe++;
        }

        if (t1->right != NULL) {
            Q1[qe] = t1->right;
            Q2[qe] = t2->right;
            qe++;
        }
    }

    return true;
}