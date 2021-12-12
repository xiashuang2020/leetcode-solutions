//
// Created by pyxisha on 2021/6/13.
//


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
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