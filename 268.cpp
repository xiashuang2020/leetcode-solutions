//
// Created by pyxisha on 2022/4/13.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = (0 + n) * (n + 1) / 2;

        for (int i : nums) {
            total -= i;
        }

        return total;
    }
};

int main(void)
{
    Solution solution;

    vector<int> test = {0, 1, 3};
    cout << solution.missingNumber(test) << endl;
}