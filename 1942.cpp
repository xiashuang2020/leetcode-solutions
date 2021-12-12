//
// Created by pyxisha on 2021/7/31.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct people {
    int idx;
    int arrive;
    int leave;
    int set;
};

static bool cmpArrive(struct people *a, struct people *b) {
    return a->arrive < b->arrive;
}

static bool cmp_leave(struct people *a, struct people *b) {
    return a->leave > b->leave;
}


class Solution {
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend) {
        struct people *friends = new people[times.size()];
        vector<struct people *> friends_in;
        vector<struct people *> friends_all;
        vector<int> set_free;
        int ret;

        for (int i = 0; i < times.size(); ++i) {
            friends[i].idx = i;
            friends[i].arrive = times[i][0];
            friends[i].leave = times[i][1];
            friends[i].set = -1;
            set_free.push_back(i);
            friends_all.push_back(friends + i);
        }

        sort(friends_all.begin(), friends_all.end(), cmpArrive);
        make_heap(set_free.begin(), set_free.end(), greater<int>());
        make_heap(friends_in.begin(), friends_in.end(), cmp_leave);

        for (auto f : friends_all) {
            while (!friends_in.empty() && friends_in[0]->leave <= f->arrive)
            {
                set_free.push_back(friends_in[0]->set);
                push_heap(set_free.begin(), set_free.end(), greater<int>());

                pop_heap(friends_in.begin(), friends_in.end(), cmp_leave);
                friends_in.pop_back();
            }

            f->set = set_free[0];
            pop_heap(set_free.begin(), set_free.end(), greater<int>());
            set_free.pop_back();

            friends_in.push_back(f);
            push_heap(friends_in.begin(), friends_in.end(), cmp_leave);

            if (f->idx == targetFriend) {
                ret = f->set;
                break;
            }

        }

        delete []friends;
        return ret;
    }
};

int main(void) {
    Solution x;

    vector<vector<int>> test = {{1, 4},
                                {2, 3},
                                {4, 6}};

    vector<vector<int>> test2 = {{3, 10},
                                {1, 5},
                                {2, 6}};

    vector<vector<int>> test3 = {{33889,98676},{80071,89737},{44118,52565},{52992,84310},{78492,88209},{21695,67063},{84622,95452},{98048,98856},
                                 {98411,99433},{55333,56548},{65375,88566},{55011,62821},{48548,48656},{87396,94825},{55273,81868},{75629,91467}};

    cout << x.smallestChair(test3, 6) << endl;

    return 0;
}