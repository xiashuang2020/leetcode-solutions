//
// Created by pyxisha on 2022/2/28.
//


#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret = "";

        while (columnNumber > 0) {
            int div = 26;
            int a = columnNumber % div;
            if (a == 0)
                a = 26;
            columnNumber = (columnNumber - a) / 26;
            char b = 'A' + (a - 1);
            ret = b + ret;
        }

        return ret;
    }
};

int main(void)
{
    Solution solution;
    cout << solution.convertToTitle(3) << endl;
    cout << solution.convertToTitle(26) << endl;
    cout << solution.convertToTitle(27) << endl;
    cout << solution.convertToTitle(28) << endl;
    cout << solution.convertToTitle(2 * 26) << endl;
    cout << solution.convertToTitle(26 * 26) << endl;
    cout << solution.convertToTitle(26 * 26 + 1) << endl;
}