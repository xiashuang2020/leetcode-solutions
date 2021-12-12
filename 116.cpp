//
// Created by pyxisha on 2021/9/5.
//

// Definition for a Node.
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        auto *currQ = new queue<Node*>;
        auto *nextQ = new queue<Node*>;

        if (root == nullptr)
            return root;

        currQ->push(root);

        while (!currQ->empty()) {
            Node* curr = currQ->front();
            currQ->pop();

            if (curr->left) {
                nextQ->push(curr->left);
            }

            if (curr->right) {
                nextQ->push(curr->right);
            }

            if (currQ->empty()) {
                curr->next = nullptr;
                swap(currQ, nextQ);
            } else {
                curr->next = currQ->front();
            }
        }

        return root;
    }
};