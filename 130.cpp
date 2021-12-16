//
// Created by pyxisha on 2021/12/16.
//

#include <vector>
#include <set>

using namespace std;


#define to_num(a, b) ((a) * 1000 + (b))

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        set<int> hash;
        vector<int> Q;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if (board[i][j] == 'O') {
                        Q.push_back(to_num(i, j));
                        hash.insert(to_num(i, j));
                    }
                }
            }
        }

        while (!Q.empty()) {
            int idx = Q.back();
            Q.pop_back();
            int ti = idx / 1000;
            int tj = idx % 1000;
            int arr[4][2] = {{ti - 1, tj}, {ti + 1, tj}, {ti, tj + 1}, {ti, tj - 1}};
            for (auto & k : arr) {
                int i = k[0];
                int j = k[1];
                if (0 <= i && i < m && 0 <= j && j < n &&
                    board[i][j] == 'O' && hash.find(to_num(i, j)) == hash.end())
                {
                    Q.push_back(to_num(i, j));
                    hash.insert(to_num(i, j));
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && hash.find(to_num(i, j)) == hash.end()) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};