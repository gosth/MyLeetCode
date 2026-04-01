class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int left_index = 0, right_index = 1;
    for (; right_index < nums.size(); ++right_index) {
      if (nums[right_index] != 0) {
        while (left_index < right_index && nums[left_index] != 0) {
          ++left_index;
        }
        if (nums[left_index] == 0) {
          std::swap(nums[right_index], nums[left_index]);
          ++left_index;
        }
      }
    }
  }
};