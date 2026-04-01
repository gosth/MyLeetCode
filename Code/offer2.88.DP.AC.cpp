class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    std::vector<int> dp(cost.size() + 1, 0);
    for (int index = 2; index <= cost.size(); ++index) {
      dp[index] = std::min(dp[index - 2] + cost[index - 2], dp[index - 1] + cost[index - 1]);
    }
    return dp[cost.size()];
  }
};