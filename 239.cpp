//
// Created by pyxisha on 2022/4/18.
//

#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> ret;

        for (int i = 0; i < k; ++i) {
            while (!window.empty() && nums[i] >= nums[window.back()]) {
                window.pop_back();
            }

            window.push_back(i);
        }

        for (int i = k; i < nums.size(); ++i) {
            ret.push_back(nums[window.front()]);

            if (!window.empty() && i - window.front() >= k)
                window.pop_front();

            while (!window.empty() && nums[i] >= nums[window.back()]) {
                window.pop_back();
            }

            window.push_back(i);
        }
        ret.push_back(nums[window.front()]);

        return ret;
    }
};

int main(void)
{
    Solution solution;
    vector<int> test = {1,3,-1,-3,5,3,6,7};

    auto ret = solution.maxSlidingWindow(test, 3);
    for (int t : ret) {
        cout << t << endl;
    }
}