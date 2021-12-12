//
// Created by pyxisha on 2021/6/13.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
Input: people = [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
Output: [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]
*/

static bool cmpx(vector<int> people1, vector<int> people2)
{
    if (people1[1] != people2[1])
        return people1[1] < people2[1];
    return people1[0] < people2[0];

}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ret;

        sort(people.begin(), people.end(), cmpx);

        for (vector<int> p : people) {
            int pos = 0;
            int prev_people = 0;
            while (prev_people < p[1]) {
                if (ret[pos][0] >= p[0])
                    prev_people++;
                pos++;
            }
            while (pos < ret.size() && ret[pos][0] <= p[0])
                pos++;
            ret.insert(ret.begin() + pos, p);
        }

        return ret;
    }
};

int main(void)
{
    class Solution x;
    vector<vector<int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};

    auto ret = x.reconstructQueue(people);
    for (vector<int> t : ret) {
        cout << t[0] << " " << t[1] << endl;
     }
    return 0;
}