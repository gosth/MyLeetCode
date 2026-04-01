#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty() || grid.front().empty()) {
            return 0;
        }
        std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid.front().size(), 0));
        dp[0][0] = grid[0][0];
        for (int line = 1; line < grid.size(); ++line) {
            dp[line][0] = dp[line - 1][0] + grid[line][0];
        }
        for (int column = 1; column < grid.front().size(); ++column) {
            dp[0][column] = dp[0][column - 1] + grid[0][column];
        }
        for (int line = 1; line < grid.size(); ++line) {
            for (int column = 1; column < grid.front().size(); ++column) {
                dp[line][column] = std::min(dp[line - 1][column], dp[line][column - 1]) + grid[line][column];
            }
        }
        return dp[grid.size() - 1][grid.front().size() - 1];
    }
};