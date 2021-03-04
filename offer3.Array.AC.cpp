class Solution {
  void swap(int* a, int* b) {
    int c = *a;
    *a = *b;
    *b = c;
  }
 public:

  int findRepeatNumber(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      while (nums[i] != i) {
        auto num = nums[i];
        if (nums[num] == num) {
          return num;
        } else {
          swap(&nums[num], &num);
        }
      }
    }
    return -1;
  }
};