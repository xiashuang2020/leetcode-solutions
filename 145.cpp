//
// Created by pyxisha on 2021/8/15.
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

static void recursive(vector<int> &ret, treeNode* node)
{
    if (node->left)
        recursive(ret, node->left);
    if (node->right)
        recursive(ret, node->right);
    ret.push_back(node->val);
}

class Solution {
public:
    vector<int> postorderTraversal(treeNode* root) {
        vector<int> ret;

        if (root == nullptr)
            return ret;

        recursive(ret, root);
        return ret;
    }
};