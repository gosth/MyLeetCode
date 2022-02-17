class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    small_top_heap.emplace(num);
    big_top_heap.emplace(small_top_heap.top());
    small_top_heap.pop();
    if (big_top_heap.size() - small_top_heap.size() > 1) {
      small_top_heap.emplace(big_top_heap.top());
      big_top_heap.pop();
    }
  }

  double findMedian() {
    if (small_top_heap.size() == big_top_heap.size()) {
      return (small_top_heap.top() + big_top_heap.top()) * 1.0 / 2;
    } else {
      return big_top_heap.top();
    }
  }

 private:
  std::priority_queue<int, std::vector<int>, std::less<int>> big_top_heap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> small_top_heap;
};