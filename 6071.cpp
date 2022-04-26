//
// Created by pyxisha on 2022/4/17.
//

#include <map>
#include <vector>

using namespace std;


class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> m;
        int ret = 0;

        for (int t : tasks) {
            if (m.find(t) != m.end())
                m[t]++;
            else
                m[t] = 1;
        }

        for () {

        }
    }
};