//
// Created by pyxisha on 2022/5/10.
//

#include <queue>
#include <iostream>

using namespace std;

class MedianFinder {
public:
    MedianFinder() {
        return;
    }

    void addNum(int num) {
        if (q1.empty()) {
            q1.push(num);
            return;
        } else if (q2.empty()) {
            q2.push(num);
            if (q1.top() > q2.top()) {
                int a = q1.top();
                int b = q2.top();
                q1.pop();
                q2.pop();
                q2.push(a);
                q1.push(b);
                return;
            }
        } else {
            if (num < q1.top()) {
                q1.push(num);
                if (q1.size() - q2.size() > 1) {
                    q2.push(q1.top());
                    q1.pop();
                }
            } else if (num > q2.top()) {
                q2.push(num);
                if (q2.size() > q1.size()) {
                    q1.push(q2.top());
                    q2.pop();
                }
            } else {
                if (q1.size() > q2.size()) {
                    q2.push(num);
                } else {
                    q1.push(num);
                }
            }
        }
    }

    double findMedian() {
        if (q1.size() == q2.size()) {
            return (0.0 + q1.top() + q2.top()) / 2;
        } else {
            return q1.top();
        }
    }

private:
    priority_queue<int, vector<int>, less<>> q1;
    priority_queue<int, vector<int>, greater<>> q2;
};

int main(void)
{
    MedianFinder medianFinder;

    medianFinder.addNum(1);
    cout << medianFinder.findMedian() << endl;
    medianFinder.addNum(2);
    cout << medianFinder.findMedian() << endl;
    medianFinder.addNum(3);
    cout << medianFinder.findMedian() << endl;
    medianFinder.addNum(4);
    cout << medianFinder.findMedian() << endl;
    medianFinder.addNum(5);
    cout << medianFinder.findMedian() << endl;
}

