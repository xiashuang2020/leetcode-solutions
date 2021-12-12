//
// Created by pyxisha on 2021/7/16.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int max = 0;
        int level_max;
        vector<int> height;

        if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;

        for (int i = 0; i < matrix[0].size(); ++i) {
            height.push_back(0);
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }

            level_max = largestRectangleArea(height);
            if (level_max > max)
                max = level_max;
        }

        return max;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> stack;
        int i = 0;
        int max_area = 0;

        while (i < heights.size()) {
            if (stack.empty() || heights[stack.back()] <= heights[i]) {
                stack.push_back(i);
                i++;
            }
            else {
                int tp = stack.back();
                stack.pop_back();
                int n_area = heights[tp] * (stack.empty() ? i : (i - stack.back() - 1));

                if (n_area > max_area)
                    max_area = n_area;

            }
        }

        while (!stack.empty()) {
            int tp = stack.back();
            stack.pop_back();
            int n_area = heights[tp] * (stack.empty() ? i : (i - stack.back() - 1));
            if (n_area > max_area)
                max_area = n_area;
        }

        return max_area;
    }
};