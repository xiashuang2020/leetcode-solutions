#include <vector>
#include <queue>
#include <iostream>

using namespace std;


class Solution {
        public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> graph;
            bool *visited = new bool[numCourses];
            bool *rec = new bool[numCourses];

            for (int i = 0; i < numCourses; ++i) {
                graph.emplace_back();
                visited[i] = false;
                rec[i] = true;
            }

            for (int i = 0; i < prerequisites.size(); ++i) {
                int k = prerequisites[i][0];
                int p = prerequisites[i][1];
                graph[p].push_back(k);
            }

            for (int i = 0; i < numCourses; ++i) {
                if (!visited[i] && dfs(i, graph, visited, rec)) {
                    delete[] visited;
                    delete[] rec;
                    return false;
                }
                    
            }

            delete[] visited;
            delete[] rec;
            return true;
        }

    private:
        bool dfs(int v, vector<vector<int>> &graph, bool *visited, bool *rec) {
            if (!visited[v]) {
                visited[v] = true;
                rec[v] = true;

                for (int sibling : graph[v]) {
                    if (!visited[sibling] && dfs(sibling, graph, visited, rec))
                        return true;
                    else if (rec[sibling])
                        return true;
                }
            }

            rec[v] = false;
            return false;
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
    cout << solution.canFinish(2, test1) << endl;
    cout << solution.canFinish(2, test2) << endl;
    cout << solution.canFinish(5, test3) << endl;
    cout << solution.canFinish(2, test4) << endl;
    cout << solution.canFinish(4, test5) << endl;
}
