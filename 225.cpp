//
// Created by pyxisha on 2022/4/13.
//

#include <queue>

using namespace  std;

class MyStack {
public:
    queue<int> *q1;
    queue<int> *q2;

    MyStack() {
        q1 = new queue<int>;
        q2 = new queue<int>;
    }

    void push(int x) {
        q2->push(x);
        while (!q1->empty()) {
            int t = q1->front();
            q2->push(t);
            q1->pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int ret = q1->front();
        q1->pop();
        return ret;
    }

    int top() {
        return q1->front();
    }

    bool empty() {
        return q1->empty();
    }
};