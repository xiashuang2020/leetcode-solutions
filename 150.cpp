//
// Created by pyxisha on 2021/8/5.
//

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        int ret;

        for (auto &s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num1 = stack.back();
                stack.pop_back();
                int num2 = stack.back();
                stack.pop_back();

                if (s == "+")
                    stack.push_back(num1 + num2);
                else if (s == "-")
                    stack.push_back(num2 - num1);
                else if (s == "*")
                    stack.push_back(num1 * num2);
                else
                    stack.push_back(num2 / num1);
            } else {
                stack.push_back(stoi(s));
            }
        }

        return stack[0];
    }
};

