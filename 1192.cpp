//
// Created by xiash on 2022/5/18.
//

#include <vector>
#include <map>
#include <iostream>
using namespace std;

struct Graph {
    int n;
    vector<vector<int>> vertexs;
};

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        Graph graph;
        ret.clear();
        int *visited = new int[n];

        graph.n = n;
        for (int i = 0; i < n; ++i) {
            graph.vertexs.emplace_back();
            visited[i] = -2;
        }

        for (auto x : connections) {
            int s = x[0];
            int d = x[1];
            graph.vertexs[s].push_back(d);
            graph.vertexs[d].push_back(s);
        }

        dfs(graph, 0, visited, 0);
        return ret;
    }

private:
    vector<vector<int>> ret;
    int dfs(Graph& graph, int node, int* visited, int depth) {
        if (visited[node] >= 0)
            return visited[node];

        visited[node] = depth;
        int min_ret_depth = depth;
        for (int sibling : graph.vertexs[node]) {
            if (visited[sibling] == depth - 1)
                continue;
            int ret_depth = dfs(graph, sibling, visited, depth + 1);
            if (ret_depth > depth) {
                ret.push_back({node, sibling});
            }
            if (ret_depth < min_ret_depth)
                min_ret_depth = ret_depth;
        }

        visited[node] = min_ret_depth;
        return min_ret_depth;
    }
};

int main(void) {
    vector<vector<int>> test = {{0, 1}, {1, 2}, {0, 2}};
    Solution solution;

    auto ret = solution.criticalConnections(3, test);
    for (auto conn : ret) {
        cout << conn[0] << " " << conn[1] << endl;
    }

    return 0;
}