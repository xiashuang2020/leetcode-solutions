//
// Created by pyxisha on 2021/6/13.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

static inline bool is_ip(string s, int st, int i)
{
    if (s[st + 0] == '0')
        return false;

    if (i == 2)
        return true;

    if (s[st + 0] < '2')
        return true;

    if (s[st + 0] == '2' && s[st + 1] < '5')
        return true;

    if (s[st + 0] == '2' && s[st + 1] == '5' && s[st + 2] <= '5')
        return true;

    return false;
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> stack;
        vector<string> ret;
        int index = 1;

        if (s.size() < 4)
            return ret;

        while (true) {
            int prev_index = stack.empty() ? 0 : stack.back();
            if (index - prev_index > 3 || (index - prev_index > 1 && !is_ip(s, prev_index, index - prev_index))) {
                if (stack.empty()) {
                    break;
                }
                stack.pop_back();
                index = prev_index + 1;
            } else {
                stack.push_back(index);
                if (stack.size() == 4) {
                    if (index == s.size()) {
                        ret.push_back(s.substr(0, stack[0]) + "." + s.substr(stack[0], stack[1] - stack[0]) + "." +
                        s.substr(stack[1], stack[2] - stack[1]) + "." + s.substr(stack[2], stack[3] - stack[2]));
                    }
                    stack.pop_back();
                    index = index + 1;
                } else {
                    index = index + 1;
                }
            }
        }

        return ret;
    }
};

int main(void)
{
    class Solution x;
    string test = "25525511135";


    auto ret = x.restoreIpAddresses(test);

    for (string t : ret) {
        cout << t << endl;
    }
}
