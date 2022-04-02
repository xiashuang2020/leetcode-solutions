//
// Created by xiash on 2022/4/1.
//

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        set<int> nums;

        for (int i = 1; i <= 9; ++i) {
            nums.insert(i);
        }

        return combinationSumRec(k, n, nums);
    }

private:
    vector<vector<int>> combinationSumRec(int k, int n, set<int> nums) {
        vector<vector<int>> ret;

        if (k == 1) {
            if (nums.find(n) != nums.end()) {
                ret.push_back({n});
                return ret;
            }
        } else {
            while (!nums.empty()) {
                int i = *nums.begin();
                nums.erase(i);
                if (i < n) {
                    auto next_ret = combinationSumRec(k - 1, n - i, nums);
                    for (auto r : next_ret) {
                        r.push_back(i);
                        ret.push_back(r);
                    }
                }
            }
        }

        return ret;
    }
};

int main(void)
{
    Solution solution;

    auto ret = solution.combinationSum3(3, 11);
    for (auto r : ret) {
        for (int x : r) {
            cout << x << " ";
        }
        cout << endl;
    }
}