class Solution {
 public:
  int cuttingRope(int n) {
    std::vector<int> dp(n + 1, 1);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
      for (int j = 1; j <= i / 2; ++j) {
        const int remained = i - j;
        dp[i] = std::max(dp[i], std::max(j, dp[j]) * std::max(remained, dp[remained]));
      }
    }
    return dp[n];
  }
};