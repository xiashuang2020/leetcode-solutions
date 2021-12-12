//
// Created by pyxisha on 2021/5/30.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res[30];

        res[0] = "1";

        for (int i = 1; i < n; ++i) {
            string orig = res[i - 1];
            char v = orig[0];
            int count = 1;
            for (int j = 1; j < orig.size(); ++j) {
                if (orig[j] == v) {
                    count++;
                } else {
                    res[i] += to_string(count) + v;
                    v = orig[j];
                    count= 1 ;
                }
            }
            res[i] += to_string(count) + v;
        }

        for (int i = 0; i < 10; ++i) {
            cout << res[i] << endl;
        }
        return res[n - 1];
    }
};

int main()
{
    class Solution x;
    x.countAndSay(10);
}