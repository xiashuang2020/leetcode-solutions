//
// Created by pyxisha on 2021/5/31.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];

}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end(), compare);

        int prev_lo = intervals[0][0];
        int prev_hi = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            int curr_lo = intervals[i][0];
            int curr_hi = intervals[i][1];
            if (curr_lo <= prev_hi) {
                prev_hi = max(curr_hi, prev_hi);
            } else {
                ret.push_back(vector<int> {prev_lo, prev_hi});
                prev_lo = curr_lo;
                prev_hi = curr_hi;
            }
        }
        ret.push_back(vector<int> {prev_lo, prev_hi});

        return ret;
    }
};

int main(void)
{
    class Solution x;
    vector<vector<int>> test = {{1,4}, {2, 3}};

    auto ret = x.merge(test);
    for (vector<int> t : ret) {
        cout << t[0] << " " << t[1] << endl;
    }
}