//
// Created by pyxisha on 2022/4/18.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        while (i < matrix.size() && i < matrix[0].size()) {
            int lo = i; int hi = matrix[0].size();
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (matrix[i][mid]  == target) {
                    return true;
                } else if (matrix[i][mid] > target) {
                    hi = mid;
                } else {
                    if (lo == mid) lo++;
                    else lo = mid;
                }
            }
            lo = i; hi = matrix.size();
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (matrix[mid][i]  == target) {
                    return true;
                } else if (matrix[mid][i] > target) {
                    hi = mid;
                } else {
                    if (lo == mid) lo++;
                    else lo = mid;
                }
            }
            i++;
        }

        return false;
    }
};


