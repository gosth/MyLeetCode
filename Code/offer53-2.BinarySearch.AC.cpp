class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int start_index = 0, end_index = nums.size();
    while (1) {
      int mid_index = start_index + (end_index - start_index) / 2;
      if (mid_index == nums[mid_index]) {
        start_index = mid_index + 1;
      } else {
        end_index = mid_index;
      }
      if (start_index == end_index) {
        return start_index;
      }
    }
  }
};