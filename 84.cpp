//
// Created by pyxisha on 2021/6/30.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
        public:
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

int main(void)
{
    class Solution x;
    vector<int> test = {2, 1, 5, 6, 2, 3};
    vector<int> test2 = {2, 1, 2};
    vector<int> test3 = {2, 4};
    vector<int> test4 = {5, 4, 1, 2};
    vector<int> test5 = {4, 2, 0, 3, 2, 5};

    cout << x.largestRectangleArea(test5) << endl;
}