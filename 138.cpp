#include <iostream>
#include <map>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        Node *curr = head, *curr2 = NULL;
        Node *nHead = NULL, *prev = NULL;

        while (curr) {
            Node * k = new Node(curr->val);
            if (!nHead)
                nHead = k;
            if (prev)
                prev->next = k;
            prev = k;
            m[curr] = k;
            curr = curr->next;
        }

        m[nullptr] = nullptr;
        curr = head;
        curr2 = nHead;

        while (curr) {
            curr2->random = m[curr->random];
            curr = curr->next;
            curr2 = curr2->next;
        }

        return nHead;
    }
};