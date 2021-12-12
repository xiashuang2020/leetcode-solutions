//
// Created by pyxisha on 2021/6/6.
//

#include <stdio.h>

struct ListNode {
    int val;
 struct ListNode *next;
};


struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    int i = 1;
    struct ListNode *curr = head;
    struct ListNode *prev = NULL, *next = NULL, *rhead = NULL;

    if (left == right)
        return head;

    while (i < left) {
        prev = curr;
        curr = curr->next;
        i++;
    }

    rhead = curr;
    while (i < right) {
        i++;
        next = curr->next;
        curr->next = next->next;
        next->next = rhead;
        rhead = next;
    }

    if (prev) {
        prev->next = next;
        return head;
    } else {
        return next;
    }
}