//
// Created by pyxisha on 2022/2/13.
//

struct ListNode {
    int val;
    struct ListNode *next;
};

#include <stdio.h>


/* 4 2 1 3*/ /* 2 4 1 3*/ /* 1 2 4 3 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *h, *p, *n, *curr, *prev;

    h = head;
    p = h->next;

    while (p) {
        n = p->next;
        curr = h;
        prev = NULL;
        while (curr->val <= p->val && curr != p) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != p) {
            if (prev != NULL) {
                prev->next = p;
                p->next = curr;
                while (curr->next != p)
                    curr = curr->next;
                curr->next = n;
            } else {
                h = p;
                p->next = curr;
                while (curr->next != p)
                    curr = curr->next;
                curr->next = n;
            }
        }


        p = n;

    }

    return h;
}