//
// Created by pyxisha on 2021/6/2.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int degree[8] = {
        1,
        2,
        3 * 2,
        4 * 3 * 2,
        5 * 4 * 3 * 2,
        6 * 5 * 4 * 3 * 2,
        7 * 6 * 5 * 4 * 3 * 2,
        8 * 7 * 6 * 5 * 4 * 3 * 2
};

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<string> tmp;
        string ret;

        k -= 1;

        for (int i = 0; i < n; ++i) {
            tmp.push_back(to_string(i + 1));
        }

        for (int i = n - 1; i > 0; i--) {
            int j = k / degree[i - 1];
            ret += tmp[j];
            tmp.erase(tmp.begin() + j);
            k -= degree[i - 1] * j;
        }

        ret += tmp[0];
        return ret;
    }
};

int main(void)
{
    class Solution x;

    cout << x.getPermutation(3, 1) << endl;
    cout << x.getPermutation(3, 2) << endl;
    cout << x.getPermutation(3, 6) << endl;
    cout << x.getPermutation(4, 4) << endl;
    cout << x.getPermutation(4, 5) << endl;
    cout << x.getPermutation(4, 7) << endl;
}