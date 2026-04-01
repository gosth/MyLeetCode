class Solution {
 public:
  int translateNum(int num) {
    std::string num2 = std::to_string(num);
    const int length = num2.size();
    std::vector<int> dp(length + 1);
    dp[0] = 1;
    dp[1] = 1;
    // num2格式为X1X2X3X4...Xi
    // dp含义为前i个字符有多少种翻译方法
    // 递推公式
    // if (10 * X(i - 1) + Xi在10和25之间) {
    //  dp[i] = dp[i - 2] + dp[i - 1]
    // } else {
    //  // 不在10到25之间
    //  dp[i] = dp[i - 1]
    // }
    for (int i = 0; i < length - 1; ++i) {
      const std::string& tempNum = num2.substr(i, 2);
      if (tempNum >= "10" && tempNum <= "25") {
        dp[i + 2] = dp[i + 1] + dp[i];
      } else {
        dp[i + 2] = dp[i + 1];
      }
    }
    return dp[length];
  }
};