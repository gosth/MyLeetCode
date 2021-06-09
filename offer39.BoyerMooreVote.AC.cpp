class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (0 == count) {
        candidate = nums[i];
        count = 1;
        continue;
      }
      if (candidate == nums[i]) {
        ++count;
      } else {
        --count;
      }
    }
    return candidate;
  }
};