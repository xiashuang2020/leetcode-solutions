//
// Created by pyxisha on 2022/5/8.
//

#include <vector>

using namespace std;

class NestedInteger {
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    NestedIterator(const vector<NestedInteger> &nestedList) {
        arr = nestedList;
        i = 0;
        if (i < nestedList.size() && !arr[i].isInteger())
            s = new NestedIterator(arr[i].getList());
        renew_s();
    }

    int next() {
        int ret;
        if (arr[i].isInteger()) {
            ret = arr[i].getInteger();
            i++;
            if (i < arr.size() && !arr[i].isInteger()) {
                s = new NestedIterator(arr[i].getList());
            }
        } else {
            ret = s->next();
        }
        renew_s();
        return ret;
    }

    bool hasNext() {
        return i < arr.size();
    }

private:
    void renew_s() {
        while (i < arr.size() && !arr[i].isInteger() && !s->hasNext()) {
            delete s;
            i++;
            if (i < arr.size() && !arr[i].isInteger())
                s = new NestedIterator(arr[i].getList());
        }

    }
    vector<NestedInteger> arr;
    NestedIterator *s;
    int i;
};