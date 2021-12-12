//
// Created by pyxisha on 2021/6/7.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr;
        string ret;
        int i = 0;

        while (i < path.size()) {
            if (path[i] == '/') {
                if (stack.empty() || stack.back() != "/") {
                    stack.emplace_back("/");
                }
                i++;
            } else {
                curr += path[i];
                if (i + 1 < path.size() && path[i + 1] != '/') {
                    i++;
                } else {
                    if (curr == ".") {
                        i += 2;
                        curr = "";
                    } else if (curr == "..") {
                        for (int j = 0; j < 3; ++j) {
                            if (stack.size() > 1) {
                                stack.pop_back();
                            }
                        }
                        curr = "";
                        i++;
                    } else {
                        stack.push_back(curr);
                        curr = "";
                        i++;
                    }
                }

            }
        }

        if (stack.size() > 1 && stack.back() == "/")
            stack.pop_back();

        for (string t : stack) {
            ret += t;
        }

        return ret;
    }
};

int main(void)
{
    class Solution x;

    cout << x.simplifyPath("/home/") << endl;
    cout << x.simplifyPath("/../") << endl;
    cout << x.simplifyPath("/home//foo/") << endl;
    cout << x.simplifyPath("/a/../b") << endl;
    cout << x.simplifyPath("/a/./b/../../c/") << endl;
}