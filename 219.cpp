//
// Created by xiash on 2022/4/6.
//

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;

        int i = 0;
        int j = 0;

        while (j < nums.size()) {
            if (j - i > k) {
                s.erase(nums[i]);
                i++;
            }
            if (s.find(nums[j]) != s.end()) {
                return true;
            } else {
                s.insert(nums[j]);
            }
            j++;
        }

        return false;
    }
};

int main(void)
{
    Solution solution;
    vector<int> test = {1, 2, 3, 1};
    cout << solution.containsNearbyDuplicate(test, 3) << endl;
    cout << solution.containsNearbyDuplicate(test, 2) << endl;
}