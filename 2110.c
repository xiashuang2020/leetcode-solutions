//
// Created by pyxisha on 2021/12/19.
//


long long getDescentPeriods(int* prices, int pricesSize){
    int count = 0;
    int idx = 0;
    long long ret = 0;

    while (idx < pricesSize) {
        if (count == 0) {
            count++;
            idx++;
        } else {
            if (prices[idx - 1] - prices[idx] == 1) {
                count++;
                idx++;
            } else {
                ret += (count + 1) * count / 2;
                count = 1;
                idx++;
            }
        }
    }

    ret += (count + 1) * count / 2;
    return ret;
}

#include <stdio.h>
int main(void)
{
    int test1[4] = { 3, 2, 1, 4 };
    int test2[4] = { 8, 6 , 7, 7};
    printf("%lld\n", getDescentPeriods(test1, 4));
    printf("%lld\n", getDescentPeriods(test2, 4));
}
