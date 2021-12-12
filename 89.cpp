//
// Created by pyxisha on 2021/6/14.
//

#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int map[65536] = {0};
        vector<int> ret;
        int ret_size = 1;
        int x = 1;

        for (int i = 0; i < n; ++i) {
            ret_size *= 2;
        }

        ret.push_back(0);
        map[0] = 1;

        loop:
        while (ret.size() < ret_size) {
            int prev_num = ret.back();
            for (; x < ret_size; x *= 2) {
                int next_num = prev_num ^ x;
                if (map[next_num] == 0) {
                    map[next_num] = 1;
                    ret.push_back(next_num);
                    x = 1;
                    goto loop;
                }
            }
            ret.pop_back();
            x = (ret.back() ^ prev_num) * 2;
        }

        return ret;
    }
};

int main(void)
{
    class Solution x;

    auto ret = x.grayCode(5);

    for (int t : ret) {
        cout << t << endl;
    }
}