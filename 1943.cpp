//
// Created by pyxisha on 2021/8/3.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int mix[100002] = {0};
        int end[100002] = {0};
        long long sum = 0;
        int lasti = 0;
        vector<vector<long long>> ret;

        for (auto &s : segments) {
            mix[s[0]] += s[2];
            mix[s[1]] -= s[2];
            end[s[0]] = 1;
            end[s[1]] = 1;
        }

        for (int i = 0; i < 100002; ++i) {
            if (end[i] && sum)
                ret.push_back({lasti, i, sum});
            sum += mix[i];
            if (end[i])
                lasti = i;
        }

        return ret;
    }
};