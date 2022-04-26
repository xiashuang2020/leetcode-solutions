//
// Created by pyxisha on 2022/3/3.
//

#include <vector>

using namespace std;

struct treeNode {
      int val;
      treeNode *left;
      treeNode *right;
      treeNode() : val(0), left(nullptr), right(nullptr) {}
      treeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      treeNode(int x, treeNode *left, treeNode *right) : val(x), left(left), right(right) {}
 };

class BSTIterator {
public:
    BSTIterator(treeNode* root) {
        auto curr = root;
        while (curr) {
            q.push_back(curr);
            curr = curr->left;
        }
    }

    int next() {
        auto ret = q.back();
        q.pop_back();
        auto c = ret->right;
        while (c != NULL) {
                q.push_back(c);
                c = c->left;
        }

        return ret->val;
    }

    bool hasNext() {
        return !q.empty();
    }

private:
    vector<struct treeNode*> q;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */