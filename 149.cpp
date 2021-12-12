//
// Created by pyxisha on 2021/8/5.
//

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int max = 0;

        for (int i = 0; i < points.size(); ++i) {
            unordered_map<double, int> slopeMap;
            for (int j = i + 1; j < points.size(); ++j) {
                double slope;

                if (points[i][0] == points[j][0])
                    slope = INT32_MAX;
                else if (points[i][1] == points[j][1])
                    slope = 0;
                else
                    slope = (double (points[j][1] - points[i][1])) / (double (points[j][0] - points[i][0]));
                slopeMap[slope]++;
                if (slopeMap[slope] > max)
                    max = slopeMap[slope];
            }
        }

        return max + 1;
    }
};

int main(void)
{
    class Solution x;

    vector<vector<int>> test = {{0,1},{0,0},{0,4},{0,-2},{0,-1},{0,3},{0,-4}};
    vector<vector<int>> test2 = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};

    cout << x.maxPoints(test) << endl;
    cout << x.maxPoints(test2) << endl;

}