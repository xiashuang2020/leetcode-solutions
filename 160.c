//
// Created by pyxisha on 2022/2/12.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


int listLen(struct ListNode *head) {
    int cnt = 0;
    struct ListNode *node = head;

    while (node) {
        cnt++;
        node = node->next;
    }

    return cnt;
}

struct ListNode *revereList(struct ListNode *head) {
    struct ListNode *prev, *next, *temp;

    prev = head; next = prev->next;
    prev->next = NULL;
    while (next) {
        temp = next->next;
        next->next = prev;
        prev = next;
        next = temp;
    }

    return prev;
}


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lista = listLen(headA);
    int listb1 = listLen(headB);
    int listb2, skip;
    struct ListNode *intersect;

    headA = revereList(headA);
    listb2 = listLen(headB);

    skip = (lista - 1 - (listb2 - listb1)) / 2;
    intersect = headA;

    while (skip > 0) {
        intersect = intersect->next;
        skip--;
    }

    revereList(headA);

    if (listb1 == listb2) {
        struct ListNode *curr = headB;
        while (curr) {
            if (curr == intersect)
                return intersect;
            curr = curr->next;
        }

        return NULL;
    }

    return intersect;
}