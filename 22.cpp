//
// Created by pyxisha on 2021/5/29.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<string> q;
        vector<string> ret;

        q.push("");

        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            int left = 0;
            int right = 0;
            for (char c : curr) {
                if (c == '(') right++;
                if (c == ')') left++;
            }

            for (char c : "()") {
                if ((c == '(' && right < n) || (c == ')' && left < right)) {
                    string news = curr + c;
                    if (news.size() == n * 2)
                        ret.push_back(news);
                    else
                        q.push(news);
                }
            }
        }


        return ret;
    }
};

int main(void) {
    class Solution x;
    vector<string> ret = x.generateParenthesis(1);

    for (string t : ret) {
        cout << t << endl;
    }
}