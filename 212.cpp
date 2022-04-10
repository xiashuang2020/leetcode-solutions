//
// Created by pyxisha on 2022/4/5.
//

#include <string>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

typedef struct trie {
    char v;
    char e;
    struct trie *childs[26];
} Trie;

Trie* trieCreate() {
    Trie *root = (Trie *)calloc(sizeof(Trie), 1);
    root->e = true;
    return root;
}

void trieInsert(Trie* obj, const char *word) {
    const char *s = word;
    Trie* node = obj;

    while (*s != 0) {
        if (node->childs[*s - 'a'] != NULL) {
            node = node->childs[*s - 'a'];
        } else {
            Trie *n_node = (Trie*)calloc(sizeof(Trie), 1);
            node->childs[*s - 'a'] = n_node;
            n_node->v = *s;
            node = n_node;
        }
        s++;
    }

    node->e = true;
}



static inline Trie* findTrie(Trie* obj, const char * word) {
    const char *s = word;
    Trie* node = obj;

    while (*s != 0) {
        if (node->childs[*s - 'a'] != NULL) {
            node = node->childs[*s - 'a'];
        } else {
            return NULL;
        }
        s++;
    }

    return node;
}

bool trieSearch(Trie* obj, const char * word) {
    Trie *node = findTrie(obj, word);

    return node != NULL && node->e;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < 26; ++i) {
        if (obj->childs[i])
            free(obj->childs[i]);
    }
    free(obj);
}

static inline bool trieEmpty(Trie* obj)
{
    for (int i = 0; i < 26; ++i) {
        if (obj->childs[i])
            return false;
    }

    return true;
}

void trieRemove(Trie* obj, const char *word) {
    if (!trieSearch(obj, word))
        return;

    vector<Trie *> st;
    const char *s = word;
    Trie* node = obj;

    st.push_back(obj);
    while (*s != 0) {
        node = node->childs[*s - 'a'];
        st.push_back(node);
        s++;
    }

    int first = 1;
    while (!st.empty()){
      Trie *d = st.back();
      st.pop_back();
      if (!trieEmpty(d)) {
          if (first) {
              d->e = 0;
              break;
          }
      } else {
          if (first || !d->e) {
              st.back()->childs[d->v - 'a'] = NULL;
              trieFree(d);
          } else {
              break;
          }
      }
      first = 0;
    }
}

bool trieStartsWith(Trie* obj, const char * prefix) {
    Trie *node = findTrie(obj, prefix);

    return node != NULL;
}



class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = trieCreate();
        vector<string> ret;

        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < words.size(); ++i) {
            trieInsert(trie, words[i].c_str());
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                string c;
                c += board[i][j];
                visited[i][j] = true;
                if (trieStartsWith(trie, c.c_str())) {
                    if (trieSearch(trie, c.c_str())) {
                        ret.push_back(c);
                        trieRemove(trie, c.c_str());
                    }
                    dfs(board, c.c_str(), trie, i, j, ret);
                }
                visited[i][j] = false;
            }
        }

        return ret;
    }

private:

    bool visited[12][12];
    void dfs (vector<vector<char>>& board, const char *prefix, Trie *trie, int i, int j, vector<string>& ret) {
        int neighbors[4][2] = {{i - 1, j}, {i + 1, j}, {i, j -1}, {i, j + 1}};

        for (int k = 0; k < 4; ++k) {
            if (0 <= neighbors[k][0] && neighbors[k][0] < board.size()
                && 0 <= neighbors[k][1] && neighbors[k][1] < board[0].size()
                && !visited[neighbors[k][0]][neighbors[k][1]]) {
                string c;
                c += prefix;
                c += board[neighbors[k][0]][neighbors[k][1]];
                visited[neighbors[k][0]][neighbors[k][1]] = true;
                if (trieStartsWith(trie, c.c_str())) {
                    if (trieSearch(trie, c.c_str())) {
                        trieRemove(trie, c.c_str());
                        ret.push_back(c);
                    }
                    dfs(board, c.c_str(), trie, neighbors[k][0], neighbors[k][1], ret);
                }
                visited[neighbors[k][0]][neighbors[k][1]] = false;
            }
        }
    }
};

#include <iostream>
int main(void)
{
    vector<vector<char>> board = {{'o','a','a','n'}, {'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words = {"oath","pea","eat","rain"};
    Solution solution;

    auto ret = solution.findWords(board, words);
    for (string s : ret) {
        cout << s << endl;
    }
}
