//
// Created by pyxisha on 2021/5/29.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *curr = NULL, *target = NULL, *prev = NULL;

    if (!head)
        return head;

    curr = target = head;

    for (int i = 0; i < n; ++i) {
        curr = curr->next;
    }

    while (curr) {
        curr = curr->next;
        prev = target;
        target = target->next;
    }

    if (prev) {
        prev->next = target->next;
    } else {
        return head->next;
    }

    return head;
}