class Solution {
public:
 bool isMatch(string s, string p) {
  int n = s.size(), m = p.size();
  std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (j == 0) {
        dp[i][j] = i == 0;
      } else {
        if (p[j - 1] != '*') {
          if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
            dp[i][j] = dp[i - 1][j - 1];
          }
        } else {
          if (j >= 2) {
            dp[i][j] = dp[i][j] | dp[i][j - 2];
          }
          if (i >= 1 && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
            dp[i][j] = dp[i][j] | dp[i - 1][j];
          }
        }
      }
    }
  }
  return dp[n][m];
}
};