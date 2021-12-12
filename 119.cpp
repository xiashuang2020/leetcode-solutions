//
// Created by pyxisha on 2021/9/6.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;

        for (int i = 0; i <= rowIndex; ++i) {
            long next;
            if (i == 0)
                ret.push_back(1);
            else {
                next = (long)(ret.back()) * (rowIndex - i + 1) / i;
                ret.push_back(next);
            }
        }

        return ret;
    }
};

int main(void) {
    Solution x;

    vector<int> ret = x.getRow(30);

    for (int x : ret) {
        cout << x << " ";
    }

    cout << endl;
}