//
// Created by pyxisha on 2021/5/30.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_len = words[0].size();
        int nword = words.size();
        vector<int> ret;
        unordered_multiset<string> set;
        int n = word_len * nword;


        for (string t : words) {
            set.insert(t);
        }

        for (int i = 0; i + n <= s.size(); ++i) {
            unordered_multiset<string> tmp = set;
            for (int j = 0; j < nword; ++j) {
                string sub = s.substr(i + j * word_len, word_len);
                if (tmp.find(sub) != tmp.end())
                    tmp.erase(tmp.find(sub));
                else {
                    break;
                }
            }

            if (tmp.empty()) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};

int main(void)
{
    class Solution x;

    string s = "wordgoodgoodgoodbestword";
    vector<string> words = {"word","good","best","good"};

    auto ret = x.findSubstring(s, words);
    for (int t : ret) {
        cout << t << endl;
    }

    return 0;
}