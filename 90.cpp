//
// Created by pyxisha on 2021/6/5.
//

#include <vector>
#include <iostream>
#include <algorithm>

#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret = {{}};
        sort(nums.begin(), nums.end());
        int size = 0;

        for (int i = 0; i < nums.size(); ++i) {

            int index = i >= 1 && nums[i] == nums[i - 1] ? size : 0;
            size = ret.size();
            for (int j = index; j < size; ++j) {
                vector<int> tmp = ret[j];
                tmp.push_back(nums[i]);
                ret.push_back(tmp);
            }
        }

        return ret;
    }
};

