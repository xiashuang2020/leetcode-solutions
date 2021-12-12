//
// Created by pyxisha on 2021/4/13.
//

struct spinlock {
    int lock;
};

void spinlock_lock(struct spinlock *lock) {
    int lv = 1;
    asm volatile (
        "1:\n"
        "xchg %[lock], %[lv]\n"
        "test %[lv], %[lv]\n"
        "jz 3f\n"
        "2:\n"
        "pause\n"
        "cmpl $0, %[lock]\n"
        "jnz 2b\n"
        "jmp 1b\n"
        "3:\n"
        : [lock] "=m" (lock->lock), [lv] "=q" (lv)
        : "[lv]" (lv) :
        "memory");

}