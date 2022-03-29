//
// Created by xiash on 2022/3/28.
//

#include <stdlib.h>
#include <stdbool.h>

typedef struct trie {
    char v;
    char e;
    struct trie *childs[26];
} Trie;

Trie* trieCreate() {
    Trie *root = calloc(sizeof(Trie), 1);
    root->e = true;
    return root;
}

void trieInsert(Trie* obj, char * word) {
    char *s = word;
    Trie* node = obj;

    while (*s != 0) {
        if (node->childs[*s - 'a'] != NULL) {
            node = node->childs[*s - 'a'];
        } else {
            Trie *n_node = calloc(sizeof(Trie), 1);
            node->childs[*s - 'a'] = n_node;
            n_node->v = *s;
            node = n_node;
        }
        s++;
    }

    node->e = true;
}

static inline Trie* findTrie(Trie* obj, char * word) {
    char *s = word;
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

bool trieSearch(Trie* obj, char * word) {
    Trie *node = findTrie(obj, word);

    return node != NULL && node->e;
}

bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *node = findTrie(obj, prefix);

    return node != NULL;
}

void trieFree(Trie* obj) {
    for (int i = 0; i < 26; ++i) {
        if (obj->childs[i])
            free(obj->childs[i]);
    }
    free(obj);
}

#include <stdio.h>
int main(void)
{
    Trie* obj = trieCreate();
    trieInsert(obj, "apple");
    printf("%d\n", trieSearch(obj, "apple"));
    printf("%d\n", trieSearch(obj, "app"));
    printf("%d\n", trieStartsWith(obj, "app"));
    trieInsert(obj, "app");
    printf("%d\n", trieSearch(obj, "app"));
    printf("%d\n", trieStartsWith(obj, "app"));
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);

 * bool param_2 = trieSearch(obj, word);

 * bool param_3 = trieStartsWith(obj, prefix);

 * trieFree(obj);
*/