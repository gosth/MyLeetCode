class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int result = 0;
    std::map<int, int> pre_sum_2_count;
    pre_sum_2_count.emplace(0, 1);
    int pre_sum = 0;
    for (const auto& num : nums) {
      pre_sum += num;
      if (pre_sum_2_count.find(pre_sum - k) != pre_sum_2_count.end()) {
        result += pre_sum_2_count[pre_sum - k];
      }
      ++pre_sum_2_count[pre_sum];
    }
    return result;
  }
};