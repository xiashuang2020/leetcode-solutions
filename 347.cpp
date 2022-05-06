//
// Created by xiash on 2022/4/28.
//

#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <set>
#include  <utility>
#include <queue>

using namespace std;



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> h;
        vector<int> ret;

        auto comp = [&h](const int &a, const int &b)  {
            if (h[a] > h[b])
                return true;
            else if (h[a] == h[b] && a > b)
                return true;
            return false;
        };
        set<int, decltype(comp)> s(comp);
        for (int i : nums) {
            s.erase(i);
            if (h.find(i) == h.end())
                h[i] = 1;
            else
                h[i] += 1;
            s.insert(i);
        }

        for (int i : s) {
            ret.push_back(i);
            if (ret.size() >= k) {
                break;
            }
        }
        return ret;
    }
};




int main(void)
{
    Solution solution;
    vector<int> test = {1, 1, 5, 6, 7, 1, 5, 5, 2, 2, 3, 4};

    auto ret = solution.topKFrequent(test, 2);
    for (int i : ret) {
        cout << i << endl;
    }
}