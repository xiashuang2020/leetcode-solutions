//
// Created by pyxisha on 2022/2/6.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool palindromeMap[2000][2001];

    int minCut(string s) {
        vector<vector<string>> ret;
        vector<string> curr;
        vector<int> trace;
        int n = s.length();
        int cut[2001];

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

        cut[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cut[i] = i;
            for (int j = 0; j < i; ++j) {
                if (palindromeMap[j][i - j])
                    if (cut[j] + 1 < cut[i])
                        cut[i] = cut[j] + 1;
            }
        }

        return cut[n] - 1;
    }
};

int main(void)
{
    Solution solution;
    cout << solution.minCut("abab") << endl;
}