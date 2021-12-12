//
// Created by pyxisha on 2021/12/12.
//



int minimumRefill(int* plants, int plantsSize, int capacityA, int capacityB){
    int idx_a = 0;
    int idx_b = plantsSize - 1;
    int cap_a = capacityA;
    int cap_b = capacityB;
    int ret = 0;

    while (idx_a <= idx_b) {
        if (idx_a != idx_b) {
            if (cap_a < plants[idx_a]) {
                ret += 1;
                cap_a = capacityA;
            }

            if ((cap_b < plants[idx_b])) {
                ret += 1;
                cap_b = capacityB;
            }
        } else {
            if (cap_a < plants[idx_a] && cap_b < plants[idx_b]) {
                ret += 1;
            }
        }

        cap_a -= plants[idx_a];
        cap_b -= plants[idx_b];

        idx_a++;
        idx_b--;
    }

    return ret;
}

#include <stdio.h>
int main(void)
{
    int arr1[4] = {2,2,3,3};
    printf("%d\n", minimumRefill(arr1, 4, 3, 4));
    printf("%d\n", minimumRefill(arr1, 4, 5, 5));
    int arr2[5] = {2, 1, 3, 3, 3};
    printf("%d\n", minimumRefill(arr2, 5, 6, 7));
    int arr3[5] = {1, 2, 4, 4, 5};
    printf("%d\n", minimumRefill(arr3, 5, 6, 5));
}