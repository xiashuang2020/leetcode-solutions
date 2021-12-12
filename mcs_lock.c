//
// Created by pyxisha on 2021/5/7.
//

#include <stdio.h>

struct mcs_lock {
    int v;
    struct mcs_lock *next;
};

#define xchg(x, b) (*x)
#define cmpxchg(a, b, c) NULL
#define cpu_relax()

void mcs_lock(struct mcs_lock **root, struct mcs_lock *new)
{
    struct mcs_lock *prev;

    new->v = 0;
    new->next = NULL;
    prev = xchg(root, new);

    if (prev == NULL) {
        return;
    }

    prev->next = new;
    while (new->v != 1) {
        cpu_relax();
    }
}

void mcs_unlock(struct mcs_lock **root, struct mcs_lock *new)
{
    struct mcs_lock *prev;

    prev = *root;
    if (prev == new) {
        if (cmpxchg(root, prev, NULL) == prev)
            return;

        while (new->next == NULL)
            cpu_relax();
    }

    new->next->v = 1;
}