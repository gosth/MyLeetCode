class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    std::unordered_map<int, int> index_mapping;
    for (int index = 0; index < arr.size(); ++index) {
      index_mapping[arr[index]] = index;
    }
    int result = 0;
    std::vector<std::vector<int>> dp(arr.size(), std::vector<int>(arr.size(), 0));
    for (int i = 2; i < arr.size(); ++i) {
      for (int j = 1; j < i; ++j) {
        int target_value = arr[i] - arr[j];
        if (auto it = index_mapping.find(target_value); it != index_mapping.end()) {
          const auto& target_index = it->second;
          if (target_index < j) {
            dp[i][j] = std::max(dp[j][target_index] + 1, 3);
            result = std::max(result, dp[i][j]);
          }
        }
      }
    }
    return result;
  }
};