//
// Created by xiash on 2022/5/6.
//

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int *dp = new int[amount + 1];
        int n = 0;
        queue<int> Q;
        queue<int> nextQ;

        Q.push(0);
        while (!Q.empty()) {
            while (!Q.empty()) {
                int p = Q.front();
                Q.pop();
                dp[p] = n;
                for (int i : coins) {
                    if (i + p <= amount && dp[i + p] == 0) {
                        nextQ.push(i + p);
                    }
                }
            }
            n++;
            swap(Q, nextQ);
        }

        return dp[amount] == 0 ? -1 : dp[amount];
    }
};

int main(void)
{
    Solution solution;
    vector<int> test = {3, 5};

    cout << solution.coinChange(test, 11) << endl;
}