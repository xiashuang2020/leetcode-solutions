//
// Created by xiash on 2022/3/21.
//

#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int dp[300][300];

struct point{
    int i;
    int j;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        memset(dp, 0, sizeof(int) * 300 * 300);
        int ret = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (dp[i][j] == 0 && grid[i][j] == '1') {
                    ret++;
                    queue<struct point> Q;
                    dp[i][j] = ret;
                    Q.push(point{i, j});
                    while (!Q.empty()) {
                        point p = Q.front();
                        point points[4] = {{p.i - 1, p.j}, {p.i + 1, p.j}, {p.i, p.j - 1}, {p.i, p.j + 1}};
                        for (int k = 0; k < 4; ++k) {
                            if (0 <= points[k].i && points[k].i < grid.size()
                                && 0 <= points[k].j && points[k].j < grid[0].size()
                                && dp[points[k].i][points[k].j] == 0 && grid[points[k].i][points[k].j] == '1') {
                                dp[points[k].i][points[k].j] = ret;
                                Q.push(points[k]);
                            }
                        }
                        Q.pop();
                    }
                }
            }
        }

        return ret;
    }
};