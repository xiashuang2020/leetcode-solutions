//
// Created by pyxisha on 2021/5/26.
//

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        vector<string> n;
        vector<string> sorted;

        for (const string &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            int find = 0;
            for (int i = 0; i < ret.size(); i++) {
                if (t == sorted[i]) {
                    find = 1;
                    ret[i].push_back(s);
                }

            }
            if (!find) {
                ret.push_back(n);
                ret.back().push_back(s);
                sorted.push_back(t);
            }
        }

        return ret;
    }
};

int main(void)
{
    class Solution x;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    auto ret = x.groupAnagrams(strs);
    return 0;
}