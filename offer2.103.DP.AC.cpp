class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (!amount) {
      return 0;
    }
    std::vector<int> Dp(amount + 1, INT_MAX);
    Dp.front() = 0;
    for (auto& item : coins) {
      if (item < Dp.size()) {
        Dp[item] = 1;
      }
    }
    for (int index = 1; index < Dp.size(); ++index) {
      if (Dp[index] == INT_MAX) {
        int min_state = INT_MAX;
        for (const auto& item : coins) {
          int candidate_index = index - item;
          if (candidate_index >= 0) {
            min_state = std::min(min_state, Dp[candidate_index]);
          }
        }
        if (min_state != INT_MAX) {
          Dp[index] = min_state + 1;
        }
      }
    }
    return Dp[amount] == INT_MAX ? -1 : Dp[amount];
  }
};