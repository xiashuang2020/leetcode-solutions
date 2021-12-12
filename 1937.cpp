//
// Created by pyxisha on 2021/7/18.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<long long> prev(n);

        for (int i = 0; i < n; ++i) {
            prev[i] = points[0][i];
        }

        for (int i = 1; i < m; ++i) {
            vector<long long> left(n, 0);
            vector<long long> right(n, 0);
            vector<long long> curr(n, 0);

            left[0] = prev[0];
            for (int j = 1; j < n; ++j) {
                left[j] = max(left[j - 1] - 1, prev[j]);
            }

            right[n - 1] = prev[n - 1];
            for (int j = n - 2; j >= 0 ; --j) {
                right[j] = max(right[j + 1] - 1, prev[j]);
            }

            for (int j = 0; j < n; ++j) {
                curr[j] = max(left[j], right[j]) + points[i][j];
            }

            prev = curr;
        }

        long long ret = prev[0];
        for (auto t: prev)
            ret = max(t, ret);

        return ret;
    }
};

int main(void)
{
    vector<vector<int>> test = {{1, 2, 3}, {1, 5, 1}, {3, 1, 1}};
    class Solution x;

    cout << x.maxPoints(test) << endl;
}