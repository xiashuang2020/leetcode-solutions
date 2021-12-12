//
// Created by pyxisha on 2021/6/14.
//

struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdio.h>

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *curr = head, *lhead = NULL, *ltail = NULL, *prev_tail = NULL, *tmp, *new_head = head;

    if (head == NULL || head->next == NULL)
        return head;

    while (curr) {
        if (curr->val < x) {
            prev_tail = curr;
            curr = curr->next;
        } else {
            if (prev_tail) {
                prev_tail->next = curr->next;
                curr->next = NULL;
                if (ltail) {
                    ltail->next = curr;
                    ltail = curr;
                } else {
                    lhead = curr;
                    ltail = curr;
                }
                curr = prev_tail->next;
            } else {
                tmp = curr->next;
                curr->next = NULL;
                if (ltail) {
                    ltail->next = curr;
                    ltail = curr;
                } else {
                    lhead = curr;
                    ltail = curr;
                }
                curr = tmp;
                new_head = curr;
            }
        }
    }

    if (prev_tail)
        prev_tail->next = lhead;

    return new_head ? new_head : lhead;
}