//
// Created by pyxisha on 2022/5/1.
//

#include <string>
#include <iostream>

using namespace std;


string tens_table[10] = {
        "",
        "",
        "Twenty",
        "Thirty",
        "Forty",
        "Fifty",
        "Sixty",
        "Seventy",
        "Eighty",
        "Ninety"
};

string ten_table[10] = {
        "Ten",
        "Eleven",
        "Twelve",
        "Thirteen",
        "Fourteen",
        "Fifteen",
        "Sixteen",
        "Seventeen",
        "Eighteen",
        "Nineteen"
};

string table[10] = {
        "Zero",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine"
};

class Solution {
public:
    string numberToWords(int num) {
        string ret;
        if (num == 0)
            return table[0];
        int n_billion = num / 1000000000;
        if (n_billion > 0) {
            ret += numberToWords(n_billion) + " Billion";
            num -= n_billion * 1000000000;
        }


        int n_million = num / 1000000;
        if (n_million > 0) {
            ret += " " + numberToWords(n_million) + " Million";
            num -= n_million * 1000000;
        }

        int n_thousand = num / 1000;
        if (n_thousand > 0) {
            ret += " " + numberToWords(n_thousand) + " Thousand";
            num -= n_thousand * 1000;
        }

        int n_hundred = num / 100;
        if (n_hundred > 0) {
            ret += " " + numberToWords(n_hundred) + " Hundred";
            num -= n_hundred * 100;
        }

        int n_ten = num / 10;
        if (n_ten >= 2) {
            ret += " " + tens_table[n_ten];
            num = num - n_ten * 10;
            if (num > 0)
                ret += " " + table[num];
        } else if (n_ten == 1) {
            num -= 10;
            ret += " " + ten_table[num];
        } else {
            if (num > 0)
                ret += " " + table[num];
        }

        return ret[0] == ' ' ? ret.substr(1) : ret;
    }
};

int main(void)
{
    Solution solution;

    cout << solution.numberToWords(123) << endl;
    cout << solution.numberToWords(1230) << endl;
    cout << solution.numberToWords(12345) << endl;
}