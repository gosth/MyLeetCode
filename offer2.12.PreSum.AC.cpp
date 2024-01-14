class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    int left_sum = 0, right_sum = sum;
    for (int index = 0; index < nums.size(); ++index) {
      if (index != 0) {
        left_sum += nums[index - 1];
      }
      right_sum -= nums[index];
      if (left_sum == right_sum) {
        return index;
      }
    }
    return -1;
  }
};