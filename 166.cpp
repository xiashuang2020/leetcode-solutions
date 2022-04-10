//
// Created by pyxisha on 2022/3/2.
//

#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ret;
        unsigned long whole;
        map<int, int> h;
        int negative = (long)numerator * (long)denominator < 0 ? 1 : 0;
        unsigned long numerator2 = abs((long)numerator);
        unsigned long denominator2 = abs((long)denominator);

        if (numerator2 > denominator2)
        {
            whole = numerator2 / denominator2;
            numerator2 -= whole * denominator2;
            ret += to_string(whole);
        } else {
            ret += "0";
        }

        if (numerator2 == 0)
            return negative ? "-" + ret : ret;
        ret += ".";
        while (numerator2 != 0) {
            numerator2 *= 10;
            if (h.find(numerator2) != h.end()) {
                string prefix = ret.substr(0, h[numerator2]);
                string loop = ret.substr(h[numerator2], ret.length() - h[numerator2]);
                ret =  prefix + "(" + loop + ")";
                break;
            } else {
                h[numerator2] = ret.length();
                if (numerator2 > denominator2) {
                    int d = numerator2 / denominator2;
                    ret += to_string(d);
                    numerator2 -= d * denominator2;

                } else {
                    ret += "0";
                }

            }
        }
        return negative ? "-" + ret : ret;
    }
};

int main(void)
{
    Solution solution;

    cout << solution.fractionToDecimal(1, 3) << endl;
    cout << solution.fractionToDecimal(2, 1) << endl;
    cout << solution.fractionToDecimal(4, 3) << endl;
    cout << solution.fractionToDecimal(1, 2) << endl;
    cout << solution.fractionToDecimal(4, 333) << endl;
    cout << solution.fractionToDecimal(-4, 333) << endl;
    cout << solution.fractionToDecimal(0, 2) << endl;
    cout << solution.fractionToDecimal(-1, -2147483648) << endl;
    cout << solution.fractionToDecimal(-2147483648, 1) << endl;
}
