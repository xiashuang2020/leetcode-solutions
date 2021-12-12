//
// Created by pyxisha on 2021/5/27.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curr;
        vector<int> dfs_index;
        int sum = 0;
        int idx = 0;

        sort(candidates.begin(), candidates.end());

        while (idx < candidates.size()) {
            sum += candidates[idx];
            curr.push_back(candidates[idx]);
            if (sum < target) {
                dfs_index.push_back(idx);
            } else {
                if (sum == target)
                    ret.push_back(curr);
                curr.pop_back();
                sum -= candidates[idx];

                if (dfs_index.empty())
                    break;
                do {
                    idx = dfs_index.back() + 1;
                    dfs_index.pop_back();
                    curr.pop_back();
                    sum -= candidates[idx - 1];
                } while(idx >= candidates.size() && dfs_index.size() > 0);
            }
        }

        return ret;
    }
};

int main(void)
{
    vector<int> foo = {4, 8, 1, 2};
    class Solution x;

    auto ret = x.combinationSum(foo, 10);
    return 0;
}