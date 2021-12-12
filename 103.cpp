//
// Created by pyxisha on 2021/8/15.
//

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int rev = 0;
        auto *curr = new queue<TreeNode*>;
        auto *next = new queue<TreeNode*>;
        vector<vector<int>> ret;
        vector<int> curr_ret;

        if (root == nullptr)
            return ret;

        curr->push(root);

        while (!curr->empty()) {
            TreeNode *node = curr->front();
            curr->pop();

            curr_ret.push_back(node->val);

            if (node->left) {
                next->push(node->left);
            }

            if (node->right) {
                next->push(node->right);
            }

            if (curr->empty()) {
                if (rev) {
                    reverse(curr_ret.begin(), curr_ret.end());
                    rev = 0;
                } else {
                    rev = 1;
                }
                ret.push_back(curr_ret);
                swap(curr, next);
                curr_ret = {};
            }
        }

        delete curr;
        delete next;

        return ret;
    }
};