//
// Created by pyxisha on 2022/2/16.
//

#include <vector>

using namespace std;

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        stack.push_back(val);
        if (stack.size() == 1) {
            m.push_back(val);
        } else {
            m.push_back(min(val, m.back()));
        }
    }

    void pop() {
        stack.pop_back();
        m.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return m.back();
    }

private:
    vector<int> stack;
    vector<int> m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */