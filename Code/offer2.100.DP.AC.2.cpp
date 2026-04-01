#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.empty() || triangle.front().empty()) {
            return 0;
        }
        std::vector<int> dp;
        dp.reserve(triangle.size());
        for (const auto &item : triangle[triangle.size() - 1]) {
            dp.emplace_back(item);
        }
        for (int i = 0; i < triangle.size() - 1; ++i) {
            for (int j = 0; j < triangle[triangle.size() - 2 - i].size(); ++j) {
                dp[j] = std::min(dp[j], dp[j + 1]) + triangle[triangle.size() - 2 - i][j];
            }
        }
        return dp.front();
    }
};