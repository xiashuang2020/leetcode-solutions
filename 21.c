//
// Created by pyxisha on 2021/4/9.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *node1 = l1;
    struct ListNode *node2 = l2;
    struct ListNode *head = NULL;
    struct ListNode *curr = NULL;

    if (l1 == NULL)
        return l2;

    if (l2 == NULL)
        return l1;

    if (node1->val <= node2->val) {
        head = node1;
        node1 = node1->next;
    } else {
        head = node2;
        node2 = node2->next;
    }

    curr = head;
    while (node1 && node2) {
        if (node1->val <= node2->val) {
            curr->next = node1;
            node1 = node1->next;
        } else {
            curr->next = node2;
            node2 = node2->next;
        }
        curr = curr->next;
    }

    if (node1)
        curr->next = node1;

    if (node2)
        curr->next = node2;


    return head;
}