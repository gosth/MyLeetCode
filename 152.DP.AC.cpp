class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    std::vector<int> max_dp(nums.size(), 0);
    std::vector<int> min_dp(nums.size(), 0);
    max_dp.front() = nums.front();
    min_dp.front() = nums.front();
    for (int index = 1; index < max_dp.size(); ++index) {
      int possible_result = max_dp[index - 1] * nums[index];
      int possible_result_2 = min_dp[index - 1] * nums[index];
      max_dp[index] = std::max(nums[index], std::max(possible_result, possible_result_2));
      min_dp[index] = std::min(nums[index], std::min(possible_result, possible_result_2));
    }
    return *std::max_element(max_dp.begin(), max_dp.end());
  }
};