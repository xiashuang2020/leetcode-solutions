//
// Created by pyxisha on 2021/5/4.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
/* 用数组保存maxtoend， 遍历一遍 */


int maxProfit(int* prices, int pricesSize){
    int max = 0;
    int buy = prices[0];
    int *maxToEnd;
    int maxPrice = 0;

    maxToEnd = calloc(pricesSize * sizeof(int), 1);

    for (int i = pricesSize - 1; i >= 0; i--) {
        maxPrice = MAX(maxPrice, prices[i]);
        maxToEnd[i] = maxPrice;
    }

    for (int i = 0; i < pricesSize - 1; ++i) {
        max = MAX(max, maxToEnd[i + 1] - prices[i]);
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