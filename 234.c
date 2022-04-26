//
// Created by pyxisha on 2022/4/17.
//

#include <stdbool.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *curr, *next, *newhead;

    if (!head)
        return head;

    newhead = head;
    curr = head;
    next = curr->next;

    while (next) {
        curr->next = next->next;
        next->next = newhead;
        newhead = next;
        next = curr->next;
    }

    return newhead;
}

bool isPalindrome(struct ListNode* head) {
    if (head->next == NULL)
        return true;

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;

    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
        if (fast->next)
            fast = fast->next;
    }

    struct ListNode *p1 = head, *p2 = slow->next;
    p2 = reverse(p2);
    slow->next = p2;
    while (p2) {
        if (p1->val == p2->val) {
            p1 = p1->next;
            p2 = p2->next;
        } else
            return false;
    }
    p2 = reverse(p2);
    slow->next = p2;

    return true;
}