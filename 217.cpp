//
// Created by pyxisha on 2022/4/5.
//

#include <set>

#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;

        for (int i = 0; i < nums.size(); ++i) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }

        return false;
    }
};