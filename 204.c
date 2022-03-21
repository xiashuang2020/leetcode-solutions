//
// Created by xiash on 2022/3/10.
//

#include <stdlib.h>

int countPrimes(int n)
{
    int ret;
    char *m;

    if (n < 2)
        return 0;

    ret = 0;
    m = calloc(1, n + 1);

    for (int i = 2; i < n; ++i) {
        if (m[i] == 0) {
            int mul = 2;
            while (mul * i < n) {
                m[mul * i] = 1;
                mul++;
            }
        }
    }

    for (int i = 2; i < n ; ++i) {
        if (m[i] == 0) {
            ret++;
        }
    }

    return ret;
}

#include <stdio.h>
int main(void)
{
    printf("%d\n", countPrimes(100));
    printf("%d\n", countPrimes(2));
    printf("%d\n", countPrimes(17));
    printf("%d\n", countPrimes(10));

}