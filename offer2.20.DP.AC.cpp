class Solution {
 public:
  int countSubstrings(string s) {
    std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
    int result = 0;
    for (int index = 0; index < s.size(); ++index) {
      dp[index][index] = 1;
      ++result;
      if (index != s.size() - 1) {
        if (s[index] == s[index + 1]) {
          dp[index][index + 1] = 1;
          ++result;
        }
      }
    }
    int max_length = s.size();
    for (int length = 3; length <= max_length; ++length) {
      for (int line = 0; line < s.size(); ++line) {
        int column = line + length - 1;
        if (column < s.size() && s[line] == s[column] && 1 == dp[line + 1][column - 1]) {
          dp[line][column] = 1;
          ++result;
        }
      }
    }
    return result;
  }
};