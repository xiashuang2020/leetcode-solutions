//
// Created by pyxisha on 2021/5/28.
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> *ret, vector<int> *curr, int sum, vector<int> &candidates, int target) {
        int i = 0;
        int prev = 0;

        for (i = 0; i < candidates.size(); i++) {
            int k = candidates[i];
            if (k == prev)
                continue;
            prev = k;
            sum += k;
            curr->push_back(k);
            if (sum < target) {
                vector<int> new_candidates;

                for (int j = i + 1; j < candidates.size(); ++j) {
                        new_candidates.push_back(candidates[j]);
                }
                dfs(ret, curr, sum, new_candidates, target);
                curr->pop_back();
                sum -= k;
            } else {
                if (sum == target) {
                    ret->push_back(*curr);
                }
                curr->pop_back();
                return;
            }
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curr;

        sort(candidates.begin(), candidates.end());
        dfs(&ret, &curr, 0, candidates, target);
        return ret;
    }
};

int main() {
    vector<int> nums = {10,1,2,7,6,1,5};
    vector<int> nums2 = {2,5,2,1,2};
    class Solution x;

    auto ret = x.combinationSum2(nums, 8);
    auto ret2 = x.combinationSum2(nums2, 5);
    return 0;
}