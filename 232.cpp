//
// Created by pyxisha on 2022/4/13.
//

#include <vector>

using namespace std;

class MyQueue {
public:
    vector<int> *s1;
    vector<int> *s2;

    MyQueue() {
        s1 = new vector<int>;
        s2 = new vector<int>;
    }

    void push(int x) {
        while (!s1->empty()) {
            int t = s1->back();
            s2->push_back(t);
            s1->pop_back();
        }
        s2->push_back(x);
        while (!s2->empty()) {
            int t = s2->back();
            s1->push_back(t);
            s2->pop_back();
        }
    }

    int pop() {
        int ret = s1->back();
        s1->pop_back();
        return ret;
    }

    int peek() {
        return s1->back();
    }

    bool empty() {
        return s1->empty();
    }
};