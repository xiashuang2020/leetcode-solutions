//
// Created by pyxisha on 2021/5/29.
//

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        unordered_map<char, char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';


        for (char c: s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    stack.push_back(c);
                    break;
                case ')':
                case ']':
                case '}':
                    if (stack.empty())
                        return false;
                    char e = stack.back();
                    if (e != map[c])
                        return false;
                    stack.pop_back();
                    break;
            }
        }

        return stack.empty();
    }
};

int main(void)
{
    class Solution solution;

    solution.isValid("()");
}