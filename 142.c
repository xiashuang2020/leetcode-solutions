//
// Created by pyxisha on 2022/2/12.
//

struct ListNode {
     int val;
     struct ListNode *next;
};

#include <stdbool.h>
#include <stdio.h>

/*
 * 2n = l + m
 * n = k + m
 * 2n = 2k + 2m
 * 2k + 2m = l + m
 * k = (l - k -m)
 */

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    bool cycle = 0;

    while (slow) {
        slow = slow->next;
        fast = fast->next;
        if (fast == NULL)
            break;
        fast = fast->next;
        if (fast == NULL)
            break;

        if (fast == slow) {
            cycle = true;
            break;
        }
    }

    if (!cycle)
        return NULL;

    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return fast;
}