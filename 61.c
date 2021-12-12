//
// Created by pyxisha on 2021/6/2.
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

struct ListNode* rotateRight(struct ListNode* head, int k) {
    int t = 1;
    struct ListNode *tail = NULL, *next_head = NULL, *prev_tail = NULL;

    if (head == NULL || head->next == NULL) {
        return head;
    }

    tail = head;
    while (tail->next) {
        tail = tail->next;
        t++;
    }

    k = k % t;
    if (k == 0)
        return head;

    next_head = head;
    k = t - k;
    while (k > 1) {
        next_head = next_head->next;
        k--;
    }
    prev_tail = next_head;
    next_head = next_head->next;

    tail->next  = head;
    prev_tail->next = NULL;
    return next_head;
}