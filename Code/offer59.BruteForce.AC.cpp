class Solution {
 public:
  int FindMaxItem(const std::vector<int>& inputs, int start_index, int end_index) {
    int value = INT_MIN;
    for (int index = start_index; index <= end_index; ++index) {
      const auto& item = inputs[index];
      if (item > value) {
        value = item;
      }
    }
    return value;
  }

  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    std::vector<int> result;
    if (nums.empty()) {
      return result;
    }
    for (int index = 0; index + k - 1 < nums.size(); ++index) {
      int end_index = index + k - 1;
      result.emplace_back(FindMaxItem(nums, index, end_index));
    }
    return result;
  }
};