//
// Created by pyxisha on 2021/6/8.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int map[128] = {0};
        int counter = t.size();
        int start = 0, end = 0;
        int d = INT32_MAX, head = 0;

        for (char x : t) {
            map[x] += 1;
        }

        while (end < s.size()) {
            map[s[end]]--;
            if (map[s[end]] >= 0) counter--;
            end++;
            while (counter == 0) {
                if (end - start < d) {
                    d = end - start;
                    head = start;
                }
                map[s[start]]++;
                if (map[s[start]] > 0)
                    counter++;
                start++;
            }
        }

        return d == INT32_MAX ? "" : s.substr(head, d);
    }
};

int main(void)
{
    class Solution x;

    cout << x.minWindow("ADOBECODEBANC", "ABC") << endl;
}