//
// Created by pyxisha on 2022/5/17.
//

#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> Q, nextQ;
        int n = 1;

        if (grid[0][0] == 1) {
            return -1;
        }

        grid[0][0] = 2;
        Q.push({0, 0});
        if (grid.size() == 1 && grid[0].size() == 1)
            return n;

        while (!Q.empty()) {
            while (!Q.empty()) {
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();

                int siblings[8][2] = {{x - 1, y - 1}, {x - 1, y}, {x - 1, y + 1},
                                      {x, y - 1}, {x, y + 1}, {x + 1, y - 1}, {x + 1, y}, {x + 1, y + 1}};

                for (int i = 0; i < 8; ++i) {
                    int nextx = siblings[i][0];
                    int nexty = siblings[i][1];

                    if (0 <= nextx && nextx < grid.size() && 0 <= nexty && nexty < grid[0].size()) {
                        if (grid[nextx][nexty] == 0) {
                            grid[nextx][nexty] = 2;
                            if (nextx == grid.size() - 1 && nexty == grid[0].size() - 1)
                                return n + 1;
                            nextQ.push({nextx, nexty});
                        }
                    }
                }
            }

            n++;
            swap(Q, nextQ);
        }

        return -1;
    }
};