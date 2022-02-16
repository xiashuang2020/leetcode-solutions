//
// Created by pyxisha on 2022/2/13.
//

#include <unordered_map>
#include <list>

using namespace std;

struct kv {
    int k;
    int v;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            int ret = (*(m[key])).v;
            l.erase(m[key]);
            l.insert(l.begin(), kv {key, ret});
            m[key] = l.begin();
            return ret;
        }

        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            l.erase(m[key]);
            l.insert(l.begin(), kv {key, value});
            m[key] = l.begin();
            return;
        } else if (m.size() < cap) {
            l.insert(l.begin(), kv {key, value});
            m[key] = l.begin();
            return;
        } else {
            kv e = l.back();
            m.erase(e.k);
            l.pop_back();
            l.insert(l.begin(), kv {key, value});
            m[key] = l.begin();
            return;
        }
    }

private:
    int cap;
    list<kv> l;
    unordered_map<int, list<kv>::iterator> m;
};
