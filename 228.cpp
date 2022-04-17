//
// Created by pyxisha on 2022/4/16.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;

        if (nums.size() == 0)
            return ret;
        int start = nums[0];
        int pre = nums[0];


        for (int i = 1; i <= nums.size(); ++i) {
            if (i < nums.size() && nums[i] == pre + 1) {
                pre = pre + 1;
            } else {
                string s;
                if (start == pre)
                    s += to_string(start);
                else
                    s += to_string(start) + "->" + to_string(pre);
                ret.push_back(s);
                if (i < nums.size())
                    start = pre = nums[i];
            }
        }

        return ret;
    }
};


int main(void)
{
    vector<int> test1 = {0,1,2,4,5,7};
    vector<int> test2 = {0,2,3,4,6,8,9};
    Solution solution;

    auto ret = solution.summaryRanges(test2);

    for (string s : ret) {
        cout << s << endl;
    }
}