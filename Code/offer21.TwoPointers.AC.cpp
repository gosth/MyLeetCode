class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    if (nums.empty()) {
      return {};
    }
    int start_index = 0, end_index = nums.size() - 1;
    while (1) {
      while (start_index < end_index && nums[start_index] % 2 == 1) {
        ++start_index;
      }
      while (start_index < end_index && nums[end_index] % 2 == 0) {
        --end_index;
      }
      if (start_index == end_index) {
        return nums;
      } else {
        std::swap(nums[start_index], nums[end_index]);
      }
    }
    // return {};
  }
};