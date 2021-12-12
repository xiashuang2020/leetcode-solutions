//
// Created by pyxisha on 2021/9/6.
//

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;

        for (int i = 0; i < numRows; ++i) {
            vector<int> curr;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    curr.push_back(1);
                } else {
                    curr.push_back(ret.back()[j - 1] + ret.back()[j]);
                }
            }
            ret.push_back(curr);
        }

        return ret;
    }
};

int main(void)
{
    Solution x;

    x.generate(5);
}
