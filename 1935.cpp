//
// Created by pyxisha on 2021/7/18.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int cant = 0;
        int total = 0;
        int map[128] = {0};

        for (int i = 0; i < brokenLetters.length(); ++i) {
            map[brokenLetters[i]] = 1;
        }

        for (int i = 0; i < text.length(); ++i) {
            if (text[i] == ' ') {
                if (!cant)
                    total += 1;
                cant = 0;
            } else {
                if (map[text[i]] == 1) {
                    cant = 1;
                }
            }
        }

        if (!cant)
            total += 1;

        return total;
    }
};

int main(void)
{
    class Solution x;

    cout << x.canBeTypedWords("hello world", "ad") << endl;
    cout << x.canBeTypedWords("leet code", "lt") << endl;
}