//
// Created by pyxisha on 2021/4/4.
//

/**
 * Definition for singly-linked list.
 */

#include <stdio.h>
#include <stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode *t1 = l1, *t2 = l2, *head = NULL, *curr = NULL;
    int lv = 0, rv = 0;

    if (t1 == NULL)
        return t2;

    if (t2 == NULL)
        return t1;

    head = calloc(sizeof(*head) * 200, 1);
    if (!head)
        return NULL;

    curr = head;

    while (t1 || t2 || carry) {
        lv = t1 ? t1->val : 0;
        rv = t2 ? t2->val : 0;
        curr->val = (lv + rv + carry) % 10;
        carry = (lv + rv + carry) / 10;
        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
        curr->next = curr + 1;
        curr = curr + 1;
    }

    (curr - 1)->next = NULL;
    return head;
}

struct ListNode num1[10];
struct ListNode num2[10];

int main(void)
{
    num1[0].val = 2;
    num1[0].next = num1 + 1;
    num1[1].val = 4;
    num1[1].next = num1 + 2;
    num1[2].val = 3;
    num2[0].val = 5;
    num2[0].next = num2 + 1;
    num2[1].val = 6;
    num2[1].next = num2 + 2;
    num2[2].val = 4;

    addTwoNumbers(num1, num2);
    return 0;
}