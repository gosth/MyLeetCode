class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    std::vector<int> result;
    std::deque<int> store;
    if (T.empty()) {
      return result;
    }
    result.resize(T.size());
    for (int i = 0; i < T.size(); ++i) {
      while (!store.empty() && T[i] > T[store.back()]) {
        result[store.back()] = i - store.back();
        store.pop_back();
      }
      store.emplace_back(i);
    }
    return result;
  }
};