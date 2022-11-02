#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.empty()) {
            return intervals;
        }
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &item1, const std::vector<int> &item2) {
            return item1.front() < item2.front();
        });
        int left = intervals.front().front(), right = intervals.front().back();
        std::vector<std::vector<int>> result;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].front() <= right) {
                right = std::max(right, intervals[i].back());
            } else {
                result.emplace_back(std::vector<int>{left, right});
                left = intervals[i].front();
                right = intervals[i].back();
            }
        }
        result.emplace_back(std::vector<int>{left, right});
        return result;
    }
};