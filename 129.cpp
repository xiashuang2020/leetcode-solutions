//
// Created by pyxisha on 2021/12/15.
//


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
    int sumNumbersR(TreeNode* root, int &path_sum)
    {
        int ret = 0;
        path_sum = path_sum * 10 + root->val;

        if (!root->left && !root->right) {
            ret = path_sum;
        }
        if (root->left) {
            ret += sumNumbersR(root->left, path_sum);
        }
        if (root->right) {
            ret += sumNumbersR(root->right, path_sum);
        }
        path_sum = (path_sum - root->val) / 10;

        return ret;
    }

    int sumNumbers(TreeNode* root) {
        int path_sum = 0;
        if (root)
            return sumNumbersR(root, path_sum);
        else
            return 0;
    }
};