//
// Created by pyxisha on 2021/12/22.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool palindromeMap[16][17];

    void dfs(string &s, vector<vector<string>> &ret, vector<string> &curr, int idx, int n) {
        int len = 1;

        while (idx + len <= n) {
            if (palindromeMap[idx][len]) {
                curr.push_back(s.substr(idx, len));
                if (idx + len < n) {
                    dfs(s, ret, curr, idx + len, n);
                    curr.pop_back();
                } else {
                    ret.push_back(curr);
                    curr.pop_back();
                    return;
                }
            }
            len++;
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> curr;
        vector<int> trace;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            palindromeMap[i][1] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1])
                palindromeMap[i][2] = true;
            else
                palindromeMap[i][2] = false;
        }

        for (int j = 3; j <= n; ++j) {
            for (int i = 0; i <= n - j; ++i) {
                if (s[i] == s[i + j - 1] && palindromeMap[i + 1][j - 2])
                    palindromeMap[i][j] = true;
                else
                    palindromeMap[i][j] = false;
            }
        }

        dfs(s, ret, curr, 0, n);
        return ret;

    }
};

int main(void)
{
    Solution solution;

    auto ret = solution.partition("aabbaa");

    for (auto a : ret) {
        for (string s : a) {
            cout << s << " ";
        }
        cout << endl;
    }
}