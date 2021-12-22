//
// Created by pyxisha on 2022/1/5.
//

#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    int pre_neg = 0;
    int pre_pos = 0;
    int s_idx = 0;

    for (int i = 0; i < gasSize; ++i) {
         int c = gas[i] - cost[i];

         if (pre_pos + c > 0) {
             if (pre_pos == 0)
                s_idx = i;
             pre_pos = pre_pos + c;
         } else {
             pre_neg = pre_neg + pre_pos + c;
             pre_pos = 0;
         }
    }

    if (pre_pos + pre_neg >= 0) {
        return s_idx;
    }
    return -1;
}

int main(void)
{
    int gas[5] = {1, 2, 3, 4, 5};
    int cost[5] = {3, 4, 5, 1, 2};

    int gas2[3] = {2, 3, 4};
    int cost2[3] = {3, 4, 3};

    int gas3[5] = {3, -2, -2, 3, -2};
    int cost3[5] = {0, 0, 0, 0, 0};

    int gas4[5] = {3, -7, 2, -1, 3};
    int cost4[5] = {0, 0, 0, 0, 0};



    printf("%d\n", canCompleteCircuit(gas, 5, cost, 5));
    printf("%d\n", canCompleteCircuit(gas2, 3, cost2, 3));
    printf("%d\n", canCompleteCircuit(gas3, 5, cost3, 5));
    printf("%d\n", canCompleteCircuit(gas4, 5, cost4, 5));
}
