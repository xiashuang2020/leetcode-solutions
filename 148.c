//
// Created by pyxisha on 2022/2/13.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2, struct ListNode **tail) {
    struct ListNode *node1 = l1;
    struct ListNode *node2 = l2;
    struct ListNode *head = NULL;
    struct ListNode *curr = NULL;


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

    if (node1) {
        curr->next = node1;
        while (node1->next)
            node1 = node1->next;
        *tail = node1;
    } else if (node2) {
        curr->next = node2;
        while (node2->next)
            node2 = node2->next;
        *tail = node2;
    } else {
        *tail = curr;
    }


    return head;
}


struct ListNode* sortList(struct ListNode* head) {
    int n = 1;
    struct ListNode *h = head;

    if (!head)
        return NULL;

    while (1)
    {
        struct ListNode *list1, *list2, *list1_tail, *list2_tail, *pre_tail = NULL, *merged_tail, *merged_head;
        struct ListNode *curr = h;
        while (curr) {
            list1 = curr;
            for (int i = 0; i < n; ++i) {
                list1_tail = curr;
                curr = curr->next;
                if (curr == NULL) {
                    if (pre_tail == NULL)
                        goto done;
                    else {
                        pre_tail->next = list1;
                        goto new_round;
                    }
                }
            }
            list2 = curr;
            for (int i = 0; i < n; ++i) {
                list2_tail = curr;
                curr = curr->next;
                if (curr == NULL)
                    break;
            }

            list1_tail->next = NULL;
            list2_tail->next = NULL;
            merged_head = mergeTwoLists(list1, list2, &merged_tail);
            if (!pre_tail)
                h = merged_head;
            else
                pre_tail->next = merged_head;
            pre_tail = merged_tail;
        }
        new_round:
        n *= 2;
    }
    done:
    return h;
}


/* 4,19,14,5,-3,1,8,5,11,15 */
struct ListNode nodes[10] = {
        {4, nodes + 1},
        {19, nodes + 2},
        {14, nodes + 3},
        {5, nodes + 4},
        {-3, nodes + 5},
        {1, nodes + 6},
        {8, nodes + 7},
        {5, nodes + 8 },
        {11, nodes + 9},
        {15, NULL},
};

int main(void)
{
    sortList(&nodes[0]);
}