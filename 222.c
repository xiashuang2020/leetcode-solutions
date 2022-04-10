//
// Created by pyxisha on 2022/4/10.
//

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static inline int height(struct TreeNode* root) {
    int ret = 0;

    while (root) {
        ret++;
        root = root->left;
    }

    return ret;
}

int countNodes(struct TreeNode* root) {
    int depth = 0;
    struct TreeNode * curr = root;
    int ret = 0;
    depth = height(root);

    if (depth == 0)
        return 0;

    if (depth == 1) {
        return 1;
    }

    curr = root;
    int rdepth = height(curr->right);
    if (rdepth == depth - 1) {
        ret += (1 << (rdepth));
        ret += countNodes(curr->right);
    } else {
        ret += (1 << (rdepth));
        ret += countNodes(curr->left);
    }


    return ret;
}