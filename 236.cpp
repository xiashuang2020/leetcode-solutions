//
// Created by pyxisha on 2022/4/17.
//


#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        search(root, p, path1);
        search(root, q, path2);

        int r = 0;
        for (int i = 1; i < path1.size(); ++i) {
            if (i < path2.size() && path2[i] == path1[i])
                r = i;
            else
                break;
        }

        return path1[r];
    }

private:
    bool search(TreeNode *root, TreeNode *node, vector<TreeNode*> &ret) {
        if (!root)
            return false;

        ret.push_back(root);
        if (root == node) {
            return true;
        }

        bool found = search(root->left, node, ret) || search(root->right, node, ret);
        if (!found)
            ret.pop_back();

        return found;
    }
};

int main(void)
{
    TreeNode node3(3);
    TreeNode node2(2);
    TreeNode node1(1);
    node1.left = &node2;
    node1.right = &node3;
    Solution solution;

    cout << solution.lowestCommonAncestor(&node1, &node2, &node3)->val << endl;


}