//
// Created by pyxisha on 2021/6/6.
//

#include <stdio.h>



struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *prev = head, *curr = NULL;

    if (head == NULL)
        return head;

    curr = prev->next;
    while (curr) {
        if (curr->val == prev->val) {
            prev->next = curr->next;
            curr = curr->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}