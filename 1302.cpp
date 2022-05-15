//
// Created by pyxisha on 2022/5/15.
//

#include <vector>

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
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode *> Q, nextQ;

        Q.push_back(root);
        while (!Q.empty()) {
            nextQ.clear();
            for (auto x : Q) {
                if (x->left) {
                    nextQ.push_back(x->left);
                }
                if (x->right) {
                    nextQ.push_back(x->right);
                }
            }

            swap(Q, nextQ);
        }

        int ret = 0;
        for (auto x : nextQ)
            ret += x->val;
        return ret;
    }
};