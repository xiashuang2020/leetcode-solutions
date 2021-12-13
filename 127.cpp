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

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<string*> pre = {&beginWord};
        vector<string*> left;

        pre.push_back(&beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            left.push_back(&wordList[i]);
        }

        int step = 1;
        while (!pre.empty()) {
            for (string* t : pre) {
                if (*t == endWord) {
                    return step;
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
            pre = next_pre;
            step++;
        }

        return 0;
    }
};

int main(void)
{
    Solution x;

    vector<string> test1 = {"hot","dot","dog","lot","log","cog"};
    cout << x.ladderLength("hit", "cog", test1) << endl;
    vector<string> test2 = {"hot","dot","dog","lot","log"};
    cout << x.ladderLength("hit", "cog", test2) << endl;
}