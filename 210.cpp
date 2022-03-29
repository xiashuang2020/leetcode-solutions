//
// Created by xiash on 2022/3/29.
//

#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ret;
        vector<set<int>> graph;
        vector<set<int>> graph2;
        set<int> Q;
        bool *visited = new bool[numCourses];
        int edges = prerequisites.size();

        for (int i = 0; i < numCourses; ++i) {
            graph.emplace_back();
            graph2.emplace_back();
            visited[i] = false;
            Q.insert(i);
        }

        for (int i = 0; i < prerequisites.size(); ++i) {
            int p = prerequisites[i][1];
            int v = prerequisites[i][0];

            graph[v].insert(p);
            graph2[p].insert(v);
            Q.erase(v);
        }

        if (Q.empty()) {
            delete[](visited);
            return ret;
        }

        for (int v : Q) {
            ret.push_back(v);
            visited[v] = true;
        }

        int i = 0;
        while (i < ret.size()) {
            int v = ret[i];
            for (int p : graph2[v]) {
                graph[p].erase(v);
                edges--;
                if (graph[p].empty() && !visited[p]) {
                    ret.push_back(p);
                    visited[p] = true;
                }
            }
            i++;
        }

        delete[](visited);
        if (edges == 0 && ret.size() == numCourses)
            return ret;
        return {};
    }
};

int main(void)
{
    Solution solution;

    vector<vector<int>> test1 = {{1, 0}};
    vector<vector<int>> test2 = {{1, 0}, {0, 1}};
    vector<vector<int>> test3 = {{1, 0}, {3, 1}, {4, 3}};
    vector<vector<int>> test4 = {{0, 1}};
    vector<vector<int>> test5 = {{1,0},{2,0},{3,1},{3,2}};
    vector<vector<int>> test6 = {{1,0},{2,1},{3,2},{1,3}};
    vector<vector<int>> test7 = {{2,1},{3,2},{1,3}};
    vector<vector<int>> test8 = {{1,2},{0,2},{0,1}};
    auto ret = solution.findOrder(2, test1);
    auto ret1 = solution.findOrder(2, test2);
    auto ret2 = solution.findOrder(5, test3);
    auto ret3 = solution.findOrder(2, test4);
    auto ret4 = solution.findOrder(4, test5);
    auto ret5 = solution.findOrder(4, test6);
    auto ret6 = solution.findOrder(4, test7);
    auto ret7 = solution.findOrder(3, test8);

    return 0;
}
