//
// Created by pyxisha on 2022/4/17.
//

#include <vector>
#include <string>

using namespace std;

struct treeNode {
    struct treeNode *parent;
    vector<treeNode *> childs;
    int m;
    int m_one;
    char c;
};

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        auto *nodes = (treeNode *)calloc(sizeof(treeNode) * parent.size(), 1);

        nodes[0].c = s[0];
        for (int i = 1; i < parent.size(); ++i) {
            nodes[i].c = s[i];
            nodes[i].parent = nodes + parent[i];
            nodes[parent[i]].childs.push_back(nodes + i);
        }

        dfs(nodes, s);
        return nodes[0].m;
    }

private: void dfs(treeNode *root, string &s) {
        if (root->childs.empty())
        {
            root->m = root->m_one = 1;
            return;
        }

        for (auto t : root->childs) {
            dfs(t, s);
        }

        int max1 = 0;
        int max2 = 0;
        for (auto t : root->childs) {
            if (root->c != t->c) {
                if (max1 < max2) {
                    if (t->m_one > max1) {
                        max1 = t->m_one;
                    }
                }
                else if (t->m_one > max2) {
                    max2 = t->m_one;
                }
            }
        }

        root->m_one = max(max1 , max2) + 1;
        root->m = max1 + max2 + 1;
        for (auto t : root->childs) {
            if (t->m > root->m)
                root->m = t->m;
        }
    }
};