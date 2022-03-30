//
// Created by xiash on 2022/3/29.
//

#include <stdlib.h>
#include <stdbool.h>

typedef struct WordDictionary{
    char v;
    char e;
    struct WordDictionary *childs[26];
} WordDictionary;

WordDictionary* wordDictionaryCreate() {
    WordDictionary *root = calloc(sizeof(WordDictionary), 1);
    root->e = true;
    return root;
}

void wordDictionaryAddWord(WordDictionary* obj, char * word) {
    char *s = word;
    WordDictionary* node = obj;

    while (*s != 0) {
        if (node->childs[*s - 'a'] != NULL) {
            node = node->childs[*s - 'a'];
        } else {
            WordDictionary *n_node = calloc(sizeof(WordDictionary), 1);
            node->childs[*s - 'a'] = n_node;
            n_node->v = *s;
            node = n_node;
        }
        s++;
    }

    node->e = true;
}

bool wordDictionarySearch(WordDictionary* obj, char *word) {
    char *s = word;
    WordDictionary *dict = obj;

    while (*s != 0) {
        if (*s == '.') {
            if (*(s + 1) != 0 ) {
                for (int i = 0; i < 26; ++i) {
                    if (dict->childs[i] != NULL && wordDictionarySearch(dict->childs[i], s + 1))
                        return true;
                }
                return false;
            } else {
                for (int i = 0; i < 26; ++i) {
                    if (dict->childs[i] != NULL && dict->childs[i]->e)
                        return true;
                }
                return false;
            }

        } else {
            if (dict->childs[*s - 'a'] == NULL) {
                return false;
            } else {
                dict = dict->childs[*s - 'a'];
            }
            s++;
        }
    }

    return dict->e == true;
}

void wordDictionaryFree(WordDictionary* obj) {
    for (int i = 0; i < 26; ++i) {
        if (obj->childs[i])
            free(obj->childs[i]);
    }
    free(obj);
}

#include <stdio.h>

int main(void)
{
    WordDictionary *wordDictionary = wordDictionaryCreate();
    wordDictionaryAddWord(wordDictionary, "bad");
    wordDictionaryAddWord(wordDictionary, "dad");
    wordDictionaryAddWord(wordDictionary, "mad");
    printf("%d\n", wordDictionarySearch(wordDictionary, "pad"));
    printf("%d\n", wordDictionarySearch(wordDictionary, "bad"));
    printf("%d\n", wordDictionarySearch(wordDictionary, ".ad"));
    printf("%d\n", wordDictionarySearch(wordDictionary, "b.."));
    printf("%d\n", wordDictionarySearch(wordDictionary, "ba."));
}
/**
 * Your WordDictionary struct will be instantiated and called as such:
 * WordDictionary* obj = wordDictionaryCreate();
 * wordDictionaryAddWord(obj, word);

 * bool param_2 = wordDictionarySearch(obj, word);

 * wordDictionaryFree(obj);
*/