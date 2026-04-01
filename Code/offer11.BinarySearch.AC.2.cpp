class Solution {
 public:
  int minArray(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums.front();
    }
    int left = 0, right = nums.size() - 1;
    while (left != right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < nums[right]) {
        right = mid;
      } else if (nums[mid] > nums[right]) {
        left = mid + 1;
      } else {
        right -= 1;
      }
    }
    return nums[left];
  }
};