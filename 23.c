//
// Created by pyxisha on 2021/4/10.
//

#include <stdlib.h>
#include <stdio.h>

/* use heap
 * heap pop -> t and heap push t->next
 * */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct heap {
    int max;
    int (*cmp)(void *a, void *b);
    int i;
    void *arr[];
};

static inline void swap(void **a, void **b)
{
    void *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

struct heap *heap_new(int n, int (*cmp)(void *a, void *b))
{
    struct heap *new = malloc(sizeof(struct heap) + sizeof(void *) * (n + 1));

    if (new == NULL)
        return NULL;

    new->max = n;
    new->i = 0;
    new->cmp = cmp;
    return new;
}

void heap_add(struct heap *heap, void *new)
{
    int k;
    int p;


    if (heap->i >= heap->max)
        return;

    heap->i++;
    k = heap->i;
    heap->arr[k] = new;

    while (k > 1) {
        p = k / 2;
        if (heap->cmp(heap->arr[k], heap->arr[p]) < 0) {
            swap(heap->arr + k, heap->arr + p);
            k = p;
        } else {
            return;
        }
    }
}

static void top_down(struct heap *heap) {
    int k, p1, p2, c;

    k = 1;
    while (2 * k <= heap->i) {
        c = k;
        p1 = 2 * k;
        p2 = 2 * k + 1;
        if (heap->cmp(heap->arr[c], heap->arr[p1]) > 0)
            c = p1;
        if (p2 <= heap->i && heap->cmp(heap->arr[c], heap->arr[p2]) > 0)
            c = p2;

        if (c == k)
            break;
        else {
            swap(heap->arr + c, heap->arr + k);
            k = c;
        }
    }
}

void *heap_replace(struct heap *heap, void * new)
{
    void *old = heap->arr[1];

    heap->arr[1] = new;
    top_down(heap);

    return old;
}

void *heap_pop(struct heap *heap)
{
    void *old = heap->arr[1];

    heap->arr[1] = heap->arr[heap->i];
    heap->i--;
    top_down(heap);

    return old;
}

int list_cmp(void *a, void *b)
{
    struct ListNode* l1 = (struct ListNode*)a;
    struct ListNode* l2 = (struct ListNode*)b;

    return l1->val - l2->val;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct heap *heap = NULL;
    struct ListNode *head = NULL, *next = NULL, *curr = NULL;
    int i;

    if (listsSize == 0)
        return NULL;

    heap = heap_new(listsSize, list_cmp);
    if (heap == NULL)
        return NULL;


    for (i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            heap_add(heap, lists[i]);
        }
    }

    while (heap->i >= 1) {
        next = (struct ListNode *)heap->arr[1];
        if (next->next) {
            heap_replace(heap, next->next);
        } else {
            heap_pop(heap);
        }

        if (head == NULL) {
            head = next;
            curr = head;
        } else {
            curr->next = next;
            curr = curr->next;
        }
    }

    free(heap);
    return head;
}

struct ListNode list1[10] = {
        {1, list1 + 1},
        {3, list1 + 2},
        {5, NULL}
};

struct ListNode list2[10] = {
        {2, list2 + 1},
        {4, list2 + 2},
        {6, NULL}
};

struct ListNode list3[10] = {
        {3, list3 + 1},
        {5, list3 + 2},
        {8, NULL}
};


int main(void)
{
    struct ListNode *lists[3] = {list1, list2, list3};
    mergeKLists(lists, 3);

    return 0;
}