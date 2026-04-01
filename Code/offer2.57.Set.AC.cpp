class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (nums.empty()) {
      return false;
    }
    std::set<int64_t> sorted_data;
    for (int index = 0; index < nums.size(); index++) {
      if (auto iter = sorted_data.lower_bound(static_cast<int64_t>(nums[index]) - t);
          iter != sorted_data.end() && *iter <= static_cast<int64_t>(nums[index]) + t) {
        return true;
      }
      sorted_data.emplace(nums[index]);
      if (sorted_data.size() >= k + 1) {
        sorted_data.erase(nums[index - k]);
      }
    }
    return false;
  }
};