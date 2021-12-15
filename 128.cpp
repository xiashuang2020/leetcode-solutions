//
// Created by pyxisha on 2021/12/14.
//

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> nums_set;
        int ret = 0;

        for (int t : nums) {
            nums_set.insert(t);
        }

        for (int x : nums_set) {
            if (nums_set.find(x - 1) == nums_set.end()) {
                int y = x + 1;
                while (nums_set.find(y) != nums_set.end()) y++;
                ret = y - x> ret ? y - x : ret;
            }
        }

        return ret;
    }
};

int main(void)
{
    Solution solution;
    vector<int> test1 = {100, 4, 200, 1, 3, 2};
    cout << solution.longestConsecutive(test1) << endl;
}