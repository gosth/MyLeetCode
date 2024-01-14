class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (!m || !n) {
      return 0;
    }
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    for (int line = 0; line < m; ++line) {
      dp[line][0] = 1;
    }
    for (int column = 0; column < n; ++column) {
      dp[0][column] = 1;
    }
    for (int line = 1; line < m; ++line) {
      for (int column = 1; column < n; ++column) {
        dp[line][column] =
            dp[line][column - 1] + dp[line - 1][column];
      }
    }
    return dp[m - 1][n - 1];
  }
};