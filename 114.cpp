//
// Created by pyxisha on 2021/9/5.
//

struct treeNode {
    int val;
    treeNode *left;
    treeNode *right;
    treeNode() : val(0), left(nullptr), right(nullptr) {}
    treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
};


class Solution {

public:
    void flatten(treeNode* root) {
        treeNode *curr = root;

        if (root == nullptr)
            return;

        while (curr) {
            if (!curr->left) {
                curr = curr->right;
            } else {
                treeNode *left = curr->left;
                treeNode *right_most = curr->left;

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
    treeNode node3(3);
    treeNode node4(4);
    treeNode node6(6);
    treeNode node2(2, &node3, &node4);
    treeNode node5(5, nullptr, &node6);
    treeNode node1(1, &node2, &node5);

    class Solution x;

    x.flatten(&node1);

    return 0;
}