class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int result = 0;
        const auto line = grid.size();
        int column = 0;
        if (line) {
            column = grid.front().size();
        }
        if (!line || !column) {
            return result;
        }
        std::vector<std::vector<int>> dp(line, std::vector<int>());
        for (int i = 0; i < dp.size(); ++i) {
            dp[i] = grid[i];
        }
        for (int j = 1; j < column; ++j) { // 第一行
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < line; ++i) { // 第一列
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < line; ++i) {
            for (int j = 1; j < column; ++j) {
                dp[i][j] = std::min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
            }
        }
        return dp[line - 1][column - 1];
    }
};