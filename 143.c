//
// Created by pyxisha on 2022/2/10.
//

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* stack[5 * 10000];

void reorderList(struct ListNode* head) {
    int n = 0, i;
    struct ListNode *curr, *tail, *tmp;

    curr = head;
    while (curr)
    {
        stack[n] = curr;
        n++;
        curr = curr->next;
    }

    if (n == 0)
        return;

    curr = head;
    i = n - 1;
    tail = stack[i];
    while (curr != tail && curr->next != tail) {
        tmp = curr->next;
        curr->next = tail;
        tail->next = tmp;
        curr = tmp;
        tail = stack[--i];
        tail->next = NULL;
    }
}