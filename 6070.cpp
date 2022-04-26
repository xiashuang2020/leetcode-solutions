//
// Created by pyxisha on 2022/4/17.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        vector<string> split;
        string p = s;


        while (p.size() > k) {
            string news;
            int i = 0;
            while (i < p.size()) {
                int n = 0;
                for (int j = 0; j < k; ++j) {
                    if (i < p.size()) {
                        n += p[i] - '0';
                        i++;
                    } else {
                        break;
                    }
                }
                news += to_string(n);
            }
            p = news;
        }

        return p;
    }
};


int main(void)
{
    Solution solution;
    cout << solution.digitSum("11111222223", 3) << endl;
    cout << solution.digitSum("0000000", 3) << endl;
}