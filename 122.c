//
// Created by pyxisha on 2021/5/4.
//

#include <stdio.h>

/* 贪心算法，低买高卖 */

int maxProfit(int* prices, int pricesSize){
    int max = 0;
    int buy = prices[0];
    int sell;
    int i;

    for (i = 1; i < pricesSize; ++i) {
        if (prices[i] < prices[i - 1]) {
            if (prices[i - 1] > buy) {
                max += prices[i - 1] - buy;
            }
            buy = prices[i];
        }
    }

    if (prices[i - 1] > buy) {
        max += prices[i - 1] - buy;
    }

    return max;
}

int main(void)
{
    int arr1[6] = {7,1,5,3,6,4};
    int arr2[6] = {1,2,3,4,5,6};
    int arr3[6] = {6,5,4,3,2,1};

    printf("%d\n", maxProfit(arr1, 6));
    printf("%d\n", maxProfit(arr2, 6));
    printf("%d\n", maxProfit(arr3, 6));
}