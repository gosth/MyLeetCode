class Solution {
 public:
  std::vector<int> GetOtherInnerIndex(int inner_index) {
    if (0 == inner_index) {
      return {1, 2};
    } else if (1 == inner_index) {
      return {0, 2};
    } else {
      return {0, 1};
    }
  }

  int minCost(vector<vector<int>>& costs) {
    std::vector<std::vector<int>> dp(costs.size(), std::vector<int>(3, 0));
    for (int index = 0; index < 3; ++index) {
      dp.front()[index] = costs.front()[index];
    }
    for (int index = 1; index < costs.size(); ++index) {
      for (int inner_index = 0; inner_index < 3; ++inner_index) {
        const std::vector<int>& other_inner_indexs = GetOtherInnerIndex(inner_index);
        dp[index][inner_index] = std::min(dp[index - 1][other_inner_indexs.front()],
                                          dp[index - 1][other_inner_indexs.back()]) +
                                 costs[index][inner_index];
      }
    }
    return *std::min_element(dp[costs.size() - 1].begin(), dp[costs.size() - 1].end());
  }
};