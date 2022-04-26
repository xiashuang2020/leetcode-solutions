//
// Created by pyxisha on 2021/9/2.
//

#include <vector>

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
    vector<vector<int>> pathSum(treeNode* root, int targetSum) {
        vector<int> curr;
        vector<vector<int>> ret;
        int sum = 0;

        if (root == nullptr)
            return ret;

        target = targetSum;
        dfs(curr, ret, sum, root);
        return ret;
    }

private:
    int target;
    void dfs(vector<int> &curr, vector<vector<int>> &ret, int &sum, treeNode* node) {
        curr.push_back(node->val);
        sum += node->val;
        if (node->left)
            dfs(curr, ret, sum, node->left);
        if (node->right)
            dfs(curr, ret, sum, node->right);
        if (node->left == nullptr && node->right == nullptr && sum == target)
            ret.push_back(curr);
        sum -= node->val;
        curr.pop_back();
    }
};