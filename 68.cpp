//
// Created by pyxisha on 2021/6/5.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        vector<string> curr_words;
        int curr_size = 0;
        int i = 0;

        while (i < words.size()) {
            string t = words[i];
            int add = 0;

            if (curr_size + t.size() + curr_words.size() <= maxWidth)
            {
                curr_size += t.size();
                curr_words.push_back(t);
                add = 1;
                i++;
            }

            if (i == words.size() || !add) {
                int wordn = curr_words.size();
                int spare = maxWidth - curr_size;
                int ninterval = wordn == 1? 1 : (wordn - 1);
                int nspace = spare / ninterval;
                int k = spare - nspace * ninterval;
                string n;

                for (int j = 0; j < wordn; ++j) {
                    int space;
                    n += curr_words[j];

                    if (i != words.size()) {
                        if (j < k) {
                            space = nspace + 1;
                        } else if (j < wordn - 1) {
                            space = nspace;
                        } else {
                            space = maxWidth - n.size();
                        }
                    } else {
                        if (j < wordn - 1) {
                            space = 1;
                        } else {
                            space = maxWidth - n.size();
                        }
                    }

                    for (int l = 0; l < space; ++l) {
                        n += ' ';
                    }
                }

                ret.push_back(n);
                curr_words.clear();
                curr_size = 0;
            }
        }

        return ret;
    }
};

int main(void) {
    vector<string> test = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    class Solution x;

    auto ret = x.fullJustify(test, 20);

    for (string t : ret) {
        cout << t << endl;
    }

    return 0;
}
