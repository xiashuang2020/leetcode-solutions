//
// Created by pyxisha on 2022/5/15.
//

#include <map>
#include <iostream>

using namespace std;

class CountIntervals {
public:
    CountIntervals() {
        sum = 0;
    }

    void add(int left, int right) {
        if (intervals.find(left) != intervals.end() && intervals[left] > right)
            return;

        if (intervals.find(left) != intervals.end())
            sum -= intervals[left] - left;

        intervals[left] = right + 1;
        sum += right + 1 - left;
        auto t = intervals.find(left);
        if (t != intervals.begin()) {
            t--;
            if (t->second >= left) {
                if (left < t->first) {
                    sum -= intervals[left];
                    intervals[left] = max(t->second, intervals[left]);
                    sum += intervals[left];
                    sum -= t->second - t->first;
                    intervals.erase(t);
                } else {
                    sum -= intervals[t->first];
                    intervals[t->first] = max(t->second, intervals[left]);
                    sum += intervals[t->first];
                    sum -= intervals[left] - left;
                    intervals.erase(left);
                    left = t->first;
                }
            }
        }

        t = intervals.upper_bound(left);
        while (t != intervals.end() && t->first <= intervals[left]) {
            sum -= intervals[left];
            intervals[left] = max(intervals[left], t->second);
            sum += intervals[left];
            sum -= t->second - t->first;
            intervals.erase(t);
            t = intervals.upper_bound(left);
        }
    }

    int count() {
        return sum;
    }

private:
    map<int, int> intervals;
    int sum;
};

int main(void)
{
    CountIntervals countIntervals;

    /* countIntervals.add(2, 3);
    countIntervals.add(7, 10);
    countIntervals.add(5, 8);

    cout << countIntervals.count() << endl; */

    /* countIntervals.add(8, 43);
    countIntervals.add(13, 16);
    countIntervals.add(26, 33); */

    countIntervals.add(616, 659);
    countIntervals.add(913, 936);
    countIntervals.add(15, 35);
    cout << countIntervals.count() << endl;

    //[[],[],[8,43],[13,16],[26,33],[28,36],[29,37],[],[34,46],[10,23]]
    //["CountIntervals","add","add","add","add","add","add","count"]
    //[[],[10,27],[46,50],[15,35],[12,32],[7,15],[49,49],[]]
}
