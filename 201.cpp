//
// Created by xiash on 2022/3/24.
//

#include <stdio.h>
#define BIT(n) (1 << (n))

int rangeBitwiseAnd(int left, int right)
{
    int ret = 0x7fffffff;

    for (int i = 0; i < 30; ++i) {
        if (left & BIT(i)) {
            unsigned int m = left;
            for (int j = 0;  j <= i ; j++) {
                m &= ~(BIT(j));
            }
            m += BIT(i + 1);
            if (m <= right)
                ret &= ~BIT(i);

        } else {
            ret &= ~BIT(i);
        }
    }

    if (left < 0x70000000)
        ret &= ~BIT(30);

    return ret;
}

int main(void)
{
    printf("%lx\n", rangeBitwiseAnd(5, 7));
    printf("%lx\n", rangeBitwiseAnd(0, 0));
    printf("%lx\n", rangeBitwiseAnd(3, 4));
    printf("%lx\n", rangeBitwiseAnd(0x707077ff, 0x7fffffff));
}