//
// Created by pyxisha on 2021/9/2.
//

#include <string.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(nullptr), right(nullptr) {}
    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    treeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode *node = head;
        treeNode *root = nullptr;

        while (node) {
            nodes[len] = new treeNode;
            nodes[len]->val = node->val;
            node = node->next;
            len += 1;
        }

        if (len == 0)
            return nullptr;

        r(0, len, &root);

        return root;
    }

private:
    treeNode *nodes[20000];
    void r(int lo, int hi, treeNode** node) {
        int mid = (lo + hi) / 2;

        *node = nodes[mid];
        if (mid > lo)
            r(lo, mid, &nodes[mid]->left);
        if (mid + 1 < hi)
            r(mid + 1, hi, &nodes[mid]->right);
    }
};