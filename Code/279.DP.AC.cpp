class Solution {
 public:
  int numSquares(int n) {
    std::vector<int> dp(n + 1, INT_MAX);
    dp[1] = 1;
    dp[0] = 0;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; i - j * j >= 0; ++j) {
        dp[i] = std::min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};