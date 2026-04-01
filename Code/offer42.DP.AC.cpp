class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int result = INT_MIN;
    // dp[i]为以第i个元素为结尾的连续子数组最大和，i>=1 && i<=n
    std::vector<int> dp(nums.size() + 1);
    dp[1] = nums.front();
    result = std::max(result, dp[1]);
    for (int i = 2; i <= nums.size(); ++i) {
      dp[i] = dp[i - 1] > 0 ? dp[i - 1] + nums[i - 1] : nums[i - 1];
      result = std::max(result, dp[i]);
    }
    return result;
  }
};