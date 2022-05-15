//
// Created by pyxisha on 2022/5/15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ret = 0;

        for (int bit = 0; bit <= 30; bit++) {
            int n = 0;
            for (int i : candidates) {
                if ((i & (1 << bit)) > 0)
                    n++;
            }
            ret = max(ret, n);
        }


        return ret;
    }
};

int main(void)
{
    Solution solution;
    vector<int> test = {33,93,31,99,74,37,3,4,2,94,77,10,75,54,24,95,65,100,41,82,35,65,38,49,85,72,67,21,20,31};
    vector<int> test2 = {16,16};
    cout << solution.largestCombination(test) << endl;
}