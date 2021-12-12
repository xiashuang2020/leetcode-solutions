//
// Created by pyxisha on 2021/7/18.
//

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;
 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        auto *curr = new queue<TreeNode*>;
        auto *next = new queue<TreeNode*>;
        int ret = 0;

        if (root == nullptr)
            return ret;

        curr->push(root);

        while (!curr->empty()) {
            TreeNode *node = curr->front();
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