#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle.front().empty()) {
            return 0;
        }
        std::vector<std::vector<int>> dp;
        dp.emplace_back(triangle.front());
        for (int line = 1; line < triangle.size(); ++line) {
            dp.emplace_back(triangle[line].size(), 0);
            for (int item_index = 0; item_index < triangle[line].size(); ++item_index) {
                if (!item_index) {
                    dp[line][item_index] =
                            dp[line - 1][item_index] +
                            triangle[line][item_index];
                    continue;
                }
                if (item_index == triangle[line].size() - 1) {
                    dp[line][item_index] =
                            dp[line - 1][item_index - 1] +
                            triangle[line][item_index];
                    continue;
                }
                dp[line][item_index] =
                        std::min(dp[line - 1][item_index - 1],
                                 dp[line - 1][item_index]) +
                                 triangle[line][item_index];
            }
        }
        return *std::min_element(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
    }
};