//
// Created by pyxisha on 2021/12/13.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int diffCharNum(string *a, string *b) {
        int ret = 0;
        for (int i = 0; i < (*a).length(); ++i) {
            if ((*a)[i] != (*b)[i])
                ret++;
        }
        return ret;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string*> pre = {&beginWord};
        vector<string*> left;
        vector<vector<string *>> levels;
        vector<vector<string>> ret;
        vector<vector<string>> next_ret;

        for (int i = 0; i < wordList.size(); i++) {
            left.push_back(&wordList[i]);
        }
        levels.push_back(pre);

        int step = 1;
        while (!pre.empty()) {
            for (string* t : pre) {
                if (*t == endWord) {
                    levels.pop_back();
                    ret.push_back({endWord});
                    while (!levels.empty()) {
                        vector<string *> p_level = levels.back();
                        levels.pop_back();
                        for (string *k : p_level) {
                            for (vector<string> rv : ret) {
                                string front = rv.front();
                                if (diffCharNum(k, &front) == 1) {
                                    rv.insert(rv.begin(), *k);
                                    next_ret.push_back(rv);
                                }
                            }
                        }
                        ret = next_ret;
                        next_ret = {};
                    }
                    return ret;
                }
            }

            vector<string*> next_pre;
            for (string* s : pre) {
                vector<string*> next_left;
                for (string* t : left) {
                    if (diffCharNum(s, t) == 1) {
                        next_pre.push_back(t);
                    } else {
                        next_left.push_back(t);
                    }
                }
                left = next_left;
            }
            levels.push_back(next_pre);
            pre = next_pre;
            step++;
        }

        return {};
    }
};

int main(void)
{
    Solution x;

    vector<string> test1 = {"hot","dot","dog","lot","log","cog"};
    auto ret1 = x.findLadders("hit", "cog", test1);
    vector<string> test2 = {"hot","dot","dog","lot","log"};
    auto ret2 = x.findLadders("hit", "cog", test2);

    return 0;
}