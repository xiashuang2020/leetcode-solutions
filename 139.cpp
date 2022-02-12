//
// Created by pyxisha on 2022/2/10.
//

#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        int dp[301] = {0};
        dp[0] = true;

        for (string k : wordDict) {
            dict.insert(k);
        }

        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.length()];
    }
};

int main(void)
{
    Solution solution;
    vector<string> dict = {"leet", "cod"};

    cout << solution.wordBreak("leetcode", dict) << endl;
}