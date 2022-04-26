//
// Created by pyxisha on 2022/4/17.
//


#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    treeNode* lowestCommonAncestor(treeNode* root, treeNode* p, treeNode* q) {
        vector<treeNode*> path1;
        vector<treeNode*> path2;

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
    bool search(treeNode *root, treeNode *node, vector<treeNode*> &ret) {
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
    treeNode node3(3);
    treeNode node2(2);
    treeNode node1(1);
    node1.left = &node2;
    node1.right = &node3;
    Solution solution;

    cout << solution.lowestCommonAncestor(&node1, &node2, &node3)->val << endl;


}