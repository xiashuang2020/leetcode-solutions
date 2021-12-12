//
// Created by pyxisha on 2021/9/5.
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
    void flatten(TreeNode* root) {
        TreeNode *curr = root;

        if (root == nullptr)
            return;

        while (curr) {
            if (!curr->left) {
                curr = curr->right;
            } else {
                TreeNode *left = curr->left;
                TreeNode *right_most = curr->left;

                while (right_most->right) {
                    right_most = right_most->right;
                }

                right_most->right = curr->right;
                curr->right = left;
                curr->left = nullptr;
                curr = curr->right;
            }
        }

        return;
    }
};

int main(void)
{
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node6(6);
    TreeNode node2(2, &node3, &node4);
    TreeNode node5(5, nullptr, &node6);
    TreeNode node1(1, &node2, &node5);

    class Solution x;

    x.flatten(&node1);

    return 0;
}