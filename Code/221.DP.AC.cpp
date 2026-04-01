class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix.front().size(), 0));
    int columns = matrix.front().size();
    int lines = matrix.size();
    int max_radius = 0;
    for (int column = 0; column < columns; ++column) {
      if ('1' == matrix[0][column]) {
        dp[0][column] = 1;
        max_radius = 1;
      }
    }
    for (int line = 0; line < lines; ++line) {
      if ('1' == matrix[line][0]) {
        dp[line][0] = 1;
        max_radius = 1;
      }
    }
    for (int line = 1; line < lines; ++line) {
      for (int column = 1; column < columns; ++column) {
        if ('1' == matrix[line][column]) {
          dp[line][column] = std::min(std::min(dp[line - 1][column], dp[line][column - 1]),
                                      dp[line - 1][column - 1]) +
                             1;
          max_radius = std::max(max_radius, dp[line][column]);
        }
      }
    }
    return max_radius * max_radius;
  }
};