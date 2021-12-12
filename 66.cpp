//
// Created by pyxisha on 2021/6/3.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int carry = 1;

        while (carry && i >= 0) {
            int n = digits[i];
            digits[i] = (n + carry) % 10;
            carry = (n + carry) / 10;
            i--;
        }

        if (carry)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

int main(void) {

    class Solution x;

    vector<int> test = {1, 2, 3};

    auto ret = x.plusOne(test);

}