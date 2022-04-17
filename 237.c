//
// Created by pyxisha on 2022/4/16.
//

struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdio.h>
void deleteNode(struct ListNode* node) {
    struct ListNode *curr = node, *next = node->next;

    while (next->next) {
        curr->val = next->val;
        curr = next;
        next = next->next;
    }

    curr->val = next->val;
    curr->next = NULL;
}