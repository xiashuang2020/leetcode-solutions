//
// Created by pyxisha on 2022/2/12.
//

#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    void dfs(vector<string> &ret, string pre, int idx, set<int> *dp, string &s) {
        if (idx < 0) {
            ret.push_back(pre);
        } else {
            for (int pidx : dp[idx]) {
                string new_pre;
                if (pre.length() != 0)
                    new_pre = s.substr(pidx, idx - pidx + 1) + " " + pre;
                else
                    new_pre = s.substr(pidx, idx - pidx + 1);
                dfs(ret, new_pre, pidx - 1, dp, s);
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<int> dp[20];
        set<string> all;
        vector<string> ret;

        for (string k : wordDict) {
            all.insert(k);
        }

        for (int i = 1; i <= s.length(); ++i) {
            for (int j = 0; j < i; ++j) {
                if ((j == 0 || !dp[j - 1].empty()) && all.find(s.substr(j, i - j)) != all.end()) {
                    dp[i - 1].insert(j);
                }
            }
        }

        dfs(ret, "", s.length() - 1, dp, s);

        return ret;
    }
};

int main(void)
{
    Solution solution;
    string s = "catsandog";
    vector<string> dict = {"cat","cats","and","sand","dog"};
    vector<string> dict2 = {"cats","dog","sand","and","cat"};

    auto ret = solution.wordBreak(s, dict2);

    for (string s : ret)
        cout << s << endl;

}