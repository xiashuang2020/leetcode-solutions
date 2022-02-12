//
// Created by pyxisha on 2022/2/7.
//

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


int cmpx(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<vector<int>> s;
        vector<int> ret;
        int total = 0;

        for (int i = 0; i < ratings.size(); ++i) {
            vector<int> c;
            c.push_back(i);
            c.push_back(ratings[i]);
            s.push_back(c);
            ret.push_back(1);
        }

        sort(s.begin(), s.end(), cmpx);
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i][0];
            int rate = s[i][1];

            if (idx > 0 && rate > ratings[idx - 1] && ret[idx] <= ret[idx - 1]) {
                ret[idx] = ret[idx - 1] + 1;
            }

            if (idx < s.size() - 1 && rate > ratings[idx + 1] && ret[idx] <= ret[idx + 1]) {
                ret[idx] = ret[idx + 1] + 1;
            }

            total += ret[idx];
        }

        return total;
    }
};

int main(void)
{
    Solution solution;

    vector<int> test1 = {1, 0, 2};
    vector<int> test2 = {1, 2, 2};

    cout << solution.candy(test1) << endl;
    cout << solution.candy(test2) << endl;
}