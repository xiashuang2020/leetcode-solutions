//
// Created by pyxisha on 2021/5/29.
//

#include <string>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        unordered_map<char, string> m;
        queue<string> q;

        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        q.push("");

        if (digits.size() == 0)
            return ret;

        while (!q.empty()) {
            string s = q.front();
            q.pop();
            char digit = digits.c_str()[s.size()];
            for (char n : m[digit]) {
                if (s.size() == digits.size() - 1)
                    ret.push_back(s + n);
                else
                    q.push(s + n);
            }

        }

        return ret;
    }
};

int main(void)
{
    string x  = "";
    class Solution solution;

    vector<string> ret = solution.letterCombinations(x);
    for (string k : ret) {
        cout << k << endl;
    }

    return 0;
}