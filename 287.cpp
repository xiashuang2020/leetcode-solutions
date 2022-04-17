//
// Created by pyxisha on 2022/4/13.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() - 1;
        int total = (1 + n) * n / 2;
        int sum = 0;


        for (int i : nums) {
            sum += i;
        }

        return sum - total;
    }
};

int main(void)
{
    Solution solution;

    vector<int> test = {1,3,4,2,2};
    cout <<  solution.findDuplicate(test) << endl;
}