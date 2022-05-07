//
// Created by xiash on 2022/5/6.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#include <stdlib.h>
#include <string.h>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;

        int *dp = new int[amount + 1];
        memset(dp, 0, sizeof(int) * (amount + 1));
        int n = 1;
        queue<int> Q;
        queue<int> nextQ;

        Q.push(0);
        while (!Q.empty()) {
            while (!Q.empty()) {
                int p = Q.front();
                Q.pop();
                for (int i : coins) {
                    if (i <= amount - p && dp[i + p] == 0) {
                        dp[i + p] = n;
                        nextQ.push(i + p);
                    }
                }
            }
            n++;
            swap(Q, nextQ);
        }

        int ret = dp[amount] == 0 ? -1 : dp[amount];
        delete[] dp;
        return ret;
    }
};

int main(void)
{
    Solution solution;
    vector<int> test = {3, 5};
    vector<int> test2 = {1, 2, 5};
    vector<int> test3 = {1, 2};

    cout << solution.coinChange(test, 11) << endl;
    cout << solution.coinChange(test2, 11) << endl;
    cout << solution.coinChange(test3, 3) << endl;
}