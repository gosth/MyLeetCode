class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    if (nums.empty()) {
      return {};
    }
    int start_index = 0, end_index = nums.size() - 1;
    while (start_index != end_index) {
      const auto& find_item = target - nums[start_index];
      if (find_item == nums[end_index]) {
        return {nums[start_index], find_item};
      } else if (find_item > nums[end_index]) {
        ++start_index;
      } else {
        --end_index;
      }
    }
    return {};
  }
};