//
// Created by pyxisha on 2022/5/14.
//

#include <vector>
#include <queue>
#include <iostream>
#include <utility>

using namespace std;

struct Node {
    vector<vector<int>> edges;
};

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        nodes = new Node[n + 1];
        visited = new int[n + 1];

        for (int i = 0; i <= n; ++i) {
            visited[i] = false;
        }

        int visited_cnt = 0;
        int ret = -1;

        for (auto e : times) {
            nodes[e[0]].edges.push_back(e);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)*> heap(cmp);
        heap.push({k, 0});
        while (!heap.empty()) {
            auto tmp = heap.top();
            heap.pop();
            int node = tmp.first;
            int distance = tmp.second;
            if (!visited[node]) {
                visited_cnt++;
                visited[node] = true;
                if (distance > ret) {
                    ret = distance;
                }
                for (auto e : nodes[node].edges) {
                    if (!visited[e[1]]) {
                        heap.push({e[1], distance + e[2]});
                    }
                }
            }
        }

        if (visited_cnt == n)
            return ret;
        return -1;
    }

private:
    Node *nodes;
    int *visited;
};



int main(void)
{
    vector<vector<int>> test = {{2,1,1},{2,3,1},{3,4,5}, {2,4,3}};

    Solution solution;
    cout << solution.networkDelayTime(test, 4, 2) << endl;

}
