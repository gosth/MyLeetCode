class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    std::vector<int> result;
    if (nums.empty()) {
      return result;
    }
    std::deque<int> queue;
    queue.emplace_back(nums.front());
    for (int index = 1; index < k; ++index) {
      const auto& item = nums[index];
      while (!queue.empty() && item > queue.back()) {
        queue.pop_back();
      }
      queue.emplace_back(item);
    }
    result.emplace_back(queue.front());
    for (int index = k; index < nums.size(); ++index) {
      const auto& item = nums[index];
      if (nums[index - k] == queue.front()) {
        queue.pop_front();
      }
      while (!queue.empty() && item > queue.back()) {
        queue.pop_back();
      }
      queue.emplace_back(item);
      result.emplace_back(queue.front());
    }
    return result;
  }
};