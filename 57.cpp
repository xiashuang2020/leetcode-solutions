//
// Created by pyxisha on 2021/5/31.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int i = 0;

        for (i = 0; i < intervals.size(); i++) {
            if (newInterval[0] > intervals[i][1]) {
                ret.push_back(intervals[i]);
            } else if (newInterval[1] < intervals[i][0]) {
                ret.push_back(newInterval);
                ret.push_back(intervals[i]);
                i += 1;
                goto rest;
            } else {
                ret.push_back(vector<int> {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])});
                goto back_merge;
            }
        }

        ret.push_back(newInterval);
        return ret;

        back_merge:
        i = i + 1;
        while (i < intervals.size() && intervals[i][0] <= ret.back()[1]) {
            ret.back()[1] = max(intervals[i][1], ret.back()[1]);
            i++;
        }

        rest:
        for (; i < intervals.size(); i++) {
            ret.push_back(intervals[i]);
        }

        return ret;
    }
};

int main(void)
{
    class Solution x;
    vector<vector<int>> test = {{1,3}, {7,8}, {9, 10}};
    //vector<vector<int>> test = {};
    vector<int> insert = {3, 11};

    auto ret = x.insert(test, insert);


    for (vector<int> t : ret) {
        cout << t[0] << " " << t[1] << endl;
    }
}