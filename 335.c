//
// Created by xiash on 2022/4/25.
//

#include <stdbool.h>
#include <stdio.h>

struct point {
    int x;
    int y;
};

struct edge {
    struct point s;
    struct point e;
};


bool isSelfCrossing(int *distance, int distanceSize)
{
    if (distanceSize <= 3)
        return false;

    for (int i = 3; i < distanceSize; ++i) {
        if (distance[i - 3] >= distance[i - 1] && distance[i] >= distance[i - 2])
            return true;
        if (i >= 4 && distance[i - 3] == distance[i - 1] && distance[i] + distance[i - 4] >= distance[i - 2])
            return true;
        if (i >= 5 && distance[i - 1] + distance[i - 5] >= distance[i - 3] && distance[i - 2] >= distance[i - 4]
            && distance[i] + distance[i - 4] >= distance[i - 2] && distance[i - 1] <= distance[i - 3])
            return true;

    }

    return false;
}

int main(void)
{
    int test1[4] = {1,2,3,4};
    printf("%d\n", isSelfCrossing(test1, 4));
    int test2[4] = {2, 1, 1, 2};
    printf("%d\n", isSelfCrossing(test2, 4));
}