
//
// Created by pyxisha on 2021/4/11.
//

#include <stdio.h>

/*
 * 五个指针，当前头，当前尾，前一个尾，curr，next
 * 最后一个k group，需要判断是否大于k
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

static int morethank(struct ListNode* head, int k)
{
    struct ListNode *curr = head;
    int t = 0;

    while (curr)
    {
        t += 1;
        if (t >= k)
            return 1;
        curr = curr->next;
    }

    return 0;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode *prev_tail = NULL, *curr = NULL, *next = NULL, *new = NULL;
    struct ListNode *curr_head = NULL, *curr_tail = NULL;
    int i = 0;

    if (head == NULL || head->next == NULL || k == 1)
        return head;

    if (!morethank(head, k))
        return head;

    curr = head;
    next = curr->next;
    curr->next = next->next;
    next->next = curr;
    i = 1;
    curr_head = next;
    curr_tail = curr;
    curr = curr->next;

    while (curr && i < k - 1) {
        curr_tail->next = curr->next;
        curr->next = curr_head;
        curr_head = curr;
        i++;
        curr = curr_tail->next;
    }

    new = curr_head;
    prev_tail = curr_tail;

    if (!morethank(curr, k))
        return new;

    while (curr) {
        if (i == k - 1) {
            if (!morethank(curr, k))
                return new;
            next = curr->next;
            prev_tail = curr_tail;
            curr->next = next->next;
            next->next = curr;
            prev_tail->next = next;
            i = 1;
            curr_head = next;
            curr_tail = curr;
            curr = curr_tail->next;
        } else {
            curr_tail->next = curr->next;
            curr->next = curr_head;
            curr_head = curr;
            prev_tail->next = curr;
            i++;
            curr = curr_tail->next;
        }
    }

    return new;
}

struct ListNode lists[10] = {
        {1, lists + 1},
        {2, lists + 2},
        {3, lists + 3},
        {4, lists + 4},
        {5, lists + 5},
        {6, 0},
        {7, lists + 7},
        {8, lists + 8},
        {9, 0}
};

int main(void) {
    reverseKGroup(lists, 3);

    return 0;
}