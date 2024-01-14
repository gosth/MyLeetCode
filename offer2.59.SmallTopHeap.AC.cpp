class KthLargest {
 public:
  KthLargest(int k, vector<int>& nums) {
    count_ = k;
    for (const auto& item: nums) {
      add(item);
    }
  }

  int add(int val) {
    small_heap.emplace(val);
    while (small_heap.size() > count_) {
      small_heap.pop();
    }
    return small_heap.top();
  }
  std::priority_queue<int, std::vector<int>, std::greater<int>> small_heap;
  int count_;
};