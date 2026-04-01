class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    std::vector<int> dp(prices.size() + 1, 0);
    if (prices.size() <= 1) {
      return 0;
    }
    dp[0] = 0;
    dp[1] = 0;
    int minPrice = prices.front();
    for (int index = 1; index < prices.size(); ++index) {
      dp[index + 1] =
          std::max(dp[index], prices[index] - minPrice);
      minPrice = std::min(minPrice, prices[index]);
    }
    return dp[prices.size()];
  }
};