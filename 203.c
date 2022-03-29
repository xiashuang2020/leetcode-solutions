//
// Created by xiash on 2022/3/25.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *pre = NULL, *curr = head, *new_head = head;

    while (curr) {
        if (curr->val == val) {
            if (pre == NULL) {
                new_head = curr->next;
                curr->next = NULL;
                curr = new_head;
            } else {
                pre->next = curr->next;
                curr->next = NULL;
                curr = pre->next;
            }
        } else {
            pre = curr;
            curr = curr->next;
        }
    }

    return new_head;
}