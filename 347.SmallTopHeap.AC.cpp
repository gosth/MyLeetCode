struct Compare {
  bool operator()(const std::pair<int, int>& item_1, const std::pair<int, int>& item_2) {
    return item_1.second > item_2.second;
  }
};

using SmallTopHeap =
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare>;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::map<int, int> frequence_mapping;
    std::vector<int> result;
    for (const auto& item : nums) {
      ++frequence_mapping[item];
    }
    SmallTopHeap heap;
    for (const auto& item : frequence_mapping) {
      if (heap.size() < k) {
        heap.emplace(item);
      } else {
        if (item.second > heap.top().second) {
          heap.pop();
          heap.emplace(item);
        }
      }
    }
    while (!heap.empty()) {
      result.emplace_back(heap.top().first);
      heap.pop();
    }
    return result;
  }
};