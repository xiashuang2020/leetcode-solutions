//
// Created by xiash on 2022/3/8.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> h;
        vector<string> ret;

        for (int i = 0; i + 10 <= s.length(); ++i) {
            string sub = s.substr(i, 10);
            if (h.find(sub) == h.end()) {
                h[sub] = 1;
            } else {
                h[sub]++;
            }
        }

        for( const auto& n : h ) {
            if (n.second > 1)
                ret.push_back(n.first);
        }


        return ret;
    }
};

int main(void)
{
    string t = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution solution;
    auto ret = solution.findRepeatedDnaSequences(t);
    for (string s : ret) {
        cout << s << endl;
    }
}
