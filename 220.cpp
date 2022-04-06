//
// Created by xiash on 2022/4/6.
//

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;

        int i = 0;
        int j = 0;

        while (j < nums.size()) {
            if (j - i > k) {
                s.erase(nums[i]);
                i++;
            }
            auto hi = s.lower_bound((long)nums[j] - t);
            if (hi != s.end() && *hi - (long)t <= (long)nums[j])
                return true;
            s.insert(nums[j]);
            j++;
        }

        return false;
    }
};

int main(void)
{
    Solution solution;
    vector<int> test = {1, 2, 3, 1};
    vector<int> test2 = {1, 5, 9, 1, 5, 9};
    cout << solution.containsNearbyAlmostDuplicate(test, 2, 1) << endl;
    cout << solution.containsNearbyAlmostDuplicate(test, 3, 0) << endl;
    cout << solution.containsNearbyAlmostDuplicate(test2, 2, 3) << endl;
    //cout << solution.containsNearbyAlmostDuplicate(test, 2, 5) << endl;
}