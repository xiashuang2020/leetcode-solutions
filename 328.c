//
// Created by pyxisha on 2022/5/10.
//


#include <stdio.h>

struct ListNode {
    int val;
     struct ListNode *next;
};



struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *odd = NULL, *even = NULL, *curr = NULL,
            *next = NULL, *old_tail = NULL, *even_tail = NULL;

    curr = head;
    while (curr) {
        next = curr->next;
        curr->next = NULL;
        if (odd == NULL) {
            odd = curr;
            old_tail = curr;
        } else {
            old_tail->next = curr;
            old_tail = curr;
        }

        if (next) {
            curr = next->next;
            next->next = NULL;
            if (even == NULL) {
                even = next;
                even_tail = next;
            } else {
                even_tail->next = next;
                even_tail = next;
            }
        } else {
            break;
        }
    }

    if (old_tail)
        old_tail->next = even;

    return odd;
}