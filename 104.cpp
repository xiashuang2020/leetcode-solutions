//
// Created by pyxisha on 2021/7/18.
//

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(nullptr), right(nullptr) {}
    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;
 
class Solution {
public:
    int maxDepth(treeNode* root) {
        auto *curr = new queue<treeNode*>;
        auto *next = new queue<treeNode*>;
        int ret = 0;

        if (root == nullptr)
            return ret;

        curr->push(root);

        while (!curr->empty()) {
            treeNode *node = curr->front();
            curr->pop();

            if (node->left) {
                next->push(node->left);
            }

            if (node->right) {
                next->push(node->right);
            }

            if (curr->empty()) {
                swap(curr, next);
                ret += 1;
            }
        }

        delete curr;
        delete next;

        return ret;
    }
};