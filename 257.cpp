//
// Created by pyxisha on 2022/4/23.
//

#include <vector>
#include <deque>
#include <string>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        dfs(root, ret, "");
        return ret;

    }

private: void dfs(TreeNode* root, vector<string> &ret, string t) {
        if (t.empty())
            t = to_string(root->val);
        else
            t += "->" + to_string(root->val);

        if (root->left == NULL && root->right == NULL)
            ret.push_back(t);

        if (root->left)
            dfs(root->left, ret, t);
        if (root->right)
            dfs(root->right, ret, t);
    }
};