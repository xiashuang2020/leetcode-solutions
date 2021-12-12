//
// Created by pyxisha on 2021/6/8.
//

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int raw_lo = 0, raw_hi = matrix.size();
        int raw_mid;

        while (raw_lo < raw_hi) {
            raw_mid = (raw_lo + raw_hi) / 2;
            if (target < matrix[raw_mid][0]) {
                raw_hi = raw_mid;
            } else if (target > matrix[raw_mid]][matrix[raw_mid].size() - 1]) {
                raw_lo = raw_lo == raw_mid ? raw_lo + 1 : raw_mid;
            } else {
                goto search_raw;
            }
        }

        return false;

        search_raw:
        int lo = 0, hi = matrix[raw_mid].size();
        int mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (target < matrix[raw_mid][mid]) {
                hi = mid;
            } else if (target > matrix[raw_mid][mid]) {
                lo = mid == lo ? lo + 1 : mid;
            } else {
                return true;
            }
        }

        return false;
    }
};