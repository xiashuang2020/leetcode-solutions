//
// Created by xiash on 2022/3/21.
//

#include <queue>
#include <iostream>
#include <vector>

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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> Q;
        queue<TreeNode *> nextQ;
        vector<int> ret;

        if (root)
            Q.push(root);

        while (!Q.empty()) {
            while (!Q.empty()) {
                TreeNode * node = Q.front();
                if (node->left)
                    nextQ.push(node->left);
                if (node->right)
                    nextQ.push(node->right);
                if (Q.size() == 1)
                    ret.push_back(node->val);
                Q.pop();
            }

            swap(Q, nextQ);
        }

        return ret;
    }
};