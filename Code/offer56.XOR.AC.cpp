class Solution {
 public:
  vector<int> singleNumbers(vector<int>& nums) {
    int xor_value = 0;
    for (const auto num : nums) {
      xor_value ^= num;
    }
    int diff_bit = 1;
    while ((xor_value & diff_bit) == 0) {
      diff_bit <<= 1;
    }
    int x = 0, y = 0;
    for (const auto num : nums) {
      if (num & diff_bit) {
        x ^= num;
      } else {
        y ^= num;
      }
    }
    return {x, y};
  }
};