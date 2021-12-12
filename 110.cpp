//
// Created by pyxisha on 2021/8/17.
//

//
// Created by pyxisha on 2021/8/17.
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

bool isBalancedR(TreeNode* root, int *height)
{
    int height_l;
    int height_r;

    if (root->left && root->right) {
         if (isBalancedR(root->left, &height_l) && isBalancedR(root->right, &height_r) && abs(height_l - height_r) <= 1) {
             *height = max(height_l, height_r) + 1;
             return true;
         } else {
             return false;
         }
    } else if (root->left) {
        *height = 2;
        return !root->left->left && !root->left->right;
    } else if (root->right) {
        *height = 2;
        return !root->right->left && !root->right->right;
    } else {
        *height = 1;
        return true;
    }

}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height;
        if (!root)
            return true;

        return isBalancedR(root, &height);
    }
};