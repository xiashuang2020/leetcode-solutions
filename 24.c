//
// Created by pyxisha on 2021/4/10.
//

/* 重点， prev 指针 */

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *curr = NULL, *next = NULL, *new_head = NULL, *prev = NULL;

    if (head == NULL || head->next == NULL)
        return head;

    curr = head;
    new_head = curr->next;
    next = curr->next;
    curr->next = next->next;
    next->next = curr;

    prev = curr;
    curr = curr->next;

    while (curr && curr->next) {
        next = curr->next;
        curr->next = next->next;
        next->next = curr;
        prev->next = next;
        prev = curr;
        curr = curr->next;
    }

    return new_head;
}