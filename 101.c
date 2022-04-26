//
// Created by pyxisha on 2021/5/2.
//

#include <stdbool.h>
#include <stdio.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

static bool treeNodeMirror(struct treeNode* node1, struct treeNode* node2)
{
    if (node1->val != node2->val)
        return false;

    if (node1->left == NULL && node2->right != NULL)
        return false;

    if (node1->left != NULL && node2->right == NULL)
        return false;

    if (node1->right == NULL && node2->left != NULL)
        return false;

    if (node1->right != NULL && node2->left == NULL)
        return false;

    return true;
}

bool isMirrorTree(struct treeNode* p, struct treeNode* q) {
    struct treeNode *Q1[100] = {0};
    struct treeNode *Q2[100] = {0};
    int qs = 0,  qe = 0;
    struct treeNode *t1 = NULL, *t2 = NULL;

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

        if (!treeNodeMirror(t1, t2))
            return false;

        if (t1->left != NULL) {
            Q1[qe] = t1->left;
            Q2[qe] = t2->right;
            qe++;
        }

        if (t1->right != NULL) {
            Q1[qe] = t1->right;
            Q2[qe] = t2->left;
            qe++;
        }
    }

    return true;
}

bool isSymmetric(struct treeNode* root){
    if (root == NULL)
        return true;

    return isMirrorTree(root->left, root->right);
}