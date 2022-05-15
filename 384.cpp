//
// Created by pyxisha on 2022/5/14.
//

#include <vector>
#include <random>

using namespace std;


class Solution {
public:
    Solution(vector<int>& nums) {
        cpy = nums;
    }

    vector<int> reset() {
        return cpy;
    }

    vector<int> shuffle() {
        vector<int> ret = cpy;

        for (int i = cpy.size() - 1; i > 0; --i) {
            int idx = random() % (i + 1);
            swap(ret[idx], ret[i]);
        }

        return ret;
    }

private:
    vector<int> cpy;
};
