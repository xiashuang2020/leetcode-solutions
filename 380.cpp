//
// Created by pyxisha on 2022/5/15.
//

#include <vector>
#include <unordered_set>
#include <random>
#include <utility>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        return;
    }

    bool insert(int val) {
        if (set.find(val) != set.end())
            return false;
        all.push_back(val);
        set.insert(val);
        return true;
    }

    bool remove(int val) {
        if (set.find(val) == set.end())
            return false;

        set.erase(val);
        return true;
    }

    int getRandom() {
        int i;
        if (all.size() * 2 < set.size()) {
            all.clear();
            for (int i: set) {
                all.push_back(i);
            }
        }

        do {
           i = random() % all.size();
        } while (set.find(all[i]) == set.end());

        return all[i];
    }

private:
    vector<int> all;
    unordered_set<int> set;
};