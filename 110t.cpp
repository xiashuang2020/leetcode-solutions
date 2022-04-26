//
// Created by pyxisha on 2021/8/17.
//

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

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
    bool isBalanced(treeNode* root) {
        int min_depth = 10000;
        int max_depth = 0;
        int curr_depth = 0;

        queue<treeNode *> *CQ = new queue<treeNode *>;
        queue<treeNode *> *NQ = new queue<treeNode *>;


        if (root == nullptr)
            return true;

        CQ->push(root);

        while (!CQ->empty()) {
            treeNode *node = CQ->front();
            CQ->pop();

            if (node->left)
                NQ->push(node->left);
            if (node->right)
                NQ->push(node->right);

            if (!node->left || !node->right) {
                if (curr_depth < min_depth)
                    min_depth = curr_depth;
                if (curr_depth > max_depth)
                    max_depth = curr_depth;
            }

            if (CQ->empty()) {
                swap(CQ, NQ);
                curr_depth++;
            }
        }

        delete CQ;
        delete NQ;
        return min_depth == max_depth || min_depth + 1 == max_depth;
    }
};