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

static void recursive(vector<int> &ret, TreeNode* node)
{
    if (node->left)
        recursive(ret, node->left);
    if (node->right)
        recursive(ret, node->right);
    ret.push_back(node->val);
}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;

        if (root == nullptr)
            return ret;

        recursive(ret, root);
        return ret;
    }
};