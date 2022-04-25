//
// Created by xiash on 2022/4/25.
//

#include <stdbool.h>

struct point {
    int x;
    int y;
};

struct edge {
    struct point s;
    struct point e;
};

enum {
    UP = 0,
    LEFT = 1,
    DOWN = 2,
    RIGHT = 3
};

bool empty(struct edge *n) {
    return n->s.x == 0 && n->s.y == 0 && n->e.x == 0 && n->e.y == 0;
}

bool helper1(struct edge *new, struct edge *judge) {
    if (!empty(&first_up) && first_up.s.x <= new.s.x &&
        new.s.x <= first_up.e.x && new.e.y >= first_up.s.y)
        return true;
}

bool isSelfCrossing(int *distance, int distanceSize)
{
    struct edge first_left = {0}, most_left = {0}, first_right = {0}, most_right = {0};
    struct edge first_down = {0}, most_down = {0}, first_up = {0}, most_up = {0};
    int direction = UP;
    struct point curr = {0};

    if (distanceSize <= 3)
        return false;

    for (int i = 0; i < distanceSize; ++i) {
        struct edge new;
        new.s = curr;
        if (direction == UP) {
            new.e.x = curr.x;
            new.e.y = curr.y + distance[i];
            if (!empty(&first_up) && first_up.s.x <= new.s.x &&
                new.s.x <= first_up.e.x && new.e.y >= first_up.s.y)
                return true;
            if (!empty(&first_up) && first_up.s.x <= new.s.x &&
                new.s.x <= first_up.e.x && new.e.y >= first_up.s.y)
                return true;
        } else if (direction == LEFT) {
            new.e.x = curr.x - distance[i];
            new.e.y = curr.y;
        } else if (direction == DOWN) {
            new.e.x = curr.x;
            new.e.y = curr.y - distance[i];
        } else {
            new.e.x = curr.x;
            new.e.y = curr.y - distance[i];
        }

        direction = (direction + 1) % 4;
    }


}