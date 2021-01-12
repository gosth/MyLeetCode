class Solution {
 public:
  int nthUglyNumber(int n) {
    if (0 == n) {
      return 0;
    }
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> store;
    std::unordered_set<int64_t> uniq;
    store.emplace(1);
    uniq.emplace(1);
    int result = 0;
    for (int index = 0; index < n; ++index) {
      const int64_t top = store.top();
      if (index == n - 1) {
        return top;
      }
      store.pop();
      if (int64_t temp = top * 2; uniq.find(temp) == uniq.end()) {
        store.emplace(temp);
        uniq.emplace(temp);
      }
      if (int64_t temp = top * 3; uniq.find(temp) == uniq.end()) {
        store.emplace(temp);
        uniq.emplace(temp);
      }
      if (int64_t temp = top * 5; uniq.find(temp) == uniq.end()) {
        store.emplace(temp);
        uniq.emplace(temp);
      }
    }
    return result;
  }
};