//
// Created by pyxisha on 2021/12/22.
//

#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};




class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> Q;
        queue<Node*> newQ;
        unordered_map<int, Node*> hash;
        set<int> visited;

        if (!node)
            return nullptr;

        Node *newRoot = new Node(node->val);

        Q.push(node);
        newQ.push(newRoot);
        visited.insert(newRoot->val);
        hash[node->val] = newRoot;

        while (!Q.empty()) {
            Node *orig = Q.front();
            Node *newq = newQ.front();
            Q.pop();
            newQ.pop();
            for (int i = 0; i < orig->neighbors.size(); ++i) {
                Node *sibling = orig->neighbors[i];
                Node *t = nullptr;
                if (hash.find(sibling->val) != hash.end()) {
                    t = hash[sibling->val];
                }
                else {
                    t = new Node(sibling->val);
                    hash[sibling->val] = t;
                }

                if (visited.find(sibling->val) == visited.end()) {
                    Q.push(sibling);
                    newQ.push(t);
                    visited.insert(t->val);
                }
                newq->neighbors.push_back(t);
            }
        }

        return newRoot;
    }
};

int main(void)
{
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    class Solution x;
    auto ret = x.cloneGraph(node1);
}