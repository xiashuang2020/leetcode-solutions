//
// Created by pyxisha on 2021/6/16.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *new_head = head;
    int val = -101;

    if (head == NULL)
        return head;

    while (curr) {
        if (curr->val == val || (curr->next && curr->next->val == curr->val)) {
            val = curr->val;
            if (prev) {
                prev->next = curr->next;
                curr = curr->next;
            } else {
                new_head = curr->next;
                curr = curr->next;
            }
        } else {
            prev = curr;
            curr = curr->next;
            val = -101;
        }

    }

    return new_head;
}