class Solution {
 public:
  int maxValue(vector<vector<int>>& grid) {
    if (grid.empty() || grid.front().empty()) {
      return 0;
    }
    int lines = grid.size(), columns = grid.front().size();
    std::vector<std::vector<int>> dp(lines, std::vector<int>(columns, 0));
    dp[0][0] = grid[0][0];
    for (int index = 1; index < lines; ++index) {
      dp[index][0] = dp[index - 1][0] + grid[index][0];
    }
    for (int index = 1; index < columns; ++index) {
      dp[0][index] = dp[0][index - 1] + grid[0][index];
    }
    for (int line_index = 1; line_index < lines; ++line_index) {
      for (int column_index = 1; column_index < columns; ++column_index) {
        dp[line_index][column_index] =
            std::max(dp[line_index][column_index - 1], dp[line_index - 1][column_index]) +
            grid[line_index][column_index];
      }
    }
    return dp[lines - 1][columns - 1];
  }
};