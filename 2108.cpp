//
// Created by pyxisha on 2021/12/19.
//

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string s : words) {
            string orig = s;
            reverse(s.begin(), s.end());
            if (s == orig)
                return orig;
        }

        return "";
    }
};