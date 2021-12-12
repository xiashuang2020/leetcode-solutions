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
        queue<vector<int>> q;

        for (int i = 1; i <= (n - k + 1) ; ++i) {
            vector<int> v {i};
            q.push(v);
        }

        while (!q.empty()) {
            vector<int> v = q.front();
            q.pop();
            int s = v.size();
            if (s == k) {
                ret.push_back(v);
            } else {
                for (int i = v[s - 1] + 1; i <= n; ++i) {
                    if (n - i + 1 < k - s)
                        break;
                    vector<int> v2 = v;
                    v2.push_back(i);
                    q.push(v2);
                }
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