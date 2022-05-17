//
// Created by pyxisha on 2022/5/17.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        queue<TreeNode*> Q1, Q2;

        if (original == target)
            return cloned;

        Q1.push(original);
        Q2.push(cloned);

        while (!Q1.empty()) {
            TreeNode *node = Q1.front();
            TreeNode *nodec = Q2.front();
            Q1.pop();
            Q2.pop();

            if (node->left) {
                if (node->left == target)
                    return nodec->left;
                Q1.push(node->left);
                Q2.push(nodec->left);
            }
            if (node->right) {
                if (node->right == target)
                    return nodec->right;
                Q1.push(node->right);
                Q2.push(nodec->right);
            }
        }


        return NULL;
    }
};