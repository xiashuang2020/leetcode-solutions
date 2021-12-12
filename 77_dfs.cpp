//
// Created by pyxisha on 2021/6/6.
//

#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> curr;
        int i = 1;

        while (!curr.empty() || i <= n) {
            if (i > n) {
                int tail = curr.back();
                i = tail + 1;
                curr.pop_back();
                continue;
            } else {
                curr.push_back(i);
                if (curr.size() == k) {
                    ret.push_back(curr);
                    curr.pop_back();
                }
                i = i + 1;
            }
        }

        return ret;
    }
};

int main(void)
{
    class Solution x;

    auto ret = x.combine(4, 3);

    for (vector<int> t : ret) {
        for (int i: t) {
            cout << i << " ";
        }
        cout << endl;
    }
}