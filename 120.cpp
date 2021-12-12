//
// Created by pyxisha on 2021/9/13.
//


#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int buf1[200] = {0};
        int buf2[200] = {0};
        int *dp = buf1;
        int *dpnext = buf2;
        int ret;

        dp[0] = triangle[0][0];

        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j == 0)
                    dpnext[j] = triangle[i][j] + dp[j];
                else if (j == i) {
                    dpnext[j] = triangle[i][j] + dp[j - 1];
                } else {
                    dpnext[j] = triangle[i][j] + min(dp[j], dp[j - 1]);
                }
            }
            swap(dp, dpnext);
        }

        ret = dp[0];
        for (int i = 1; i < triangle.size(); i++) {
            if (dp[i] < ret)
                ret = dp[i];
        }

        return ret;
    }
};

int main(void)
{
    vector<vector<int>> test = {{2}, {3, 4}, {6,5,7}, {4,1,8,3}};
    class Solution x;

    cout << x.minimumTotal(test) << endl;
}