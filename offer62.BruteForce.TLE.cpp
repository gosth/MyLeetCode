class Solution {
 public:
  int lastRemaining(int n, int m) {
    std::set<int> collection;
    for (int i = 0; i < n; ++i) {
      collection.emplace(i);
    }
    auto iter = collection.begin();
    while (collection.size() != 1) {
      int counter = m;
      while (--counter) {
        if (iter == collection.end()) {
          iter = collection.begin();
        }
        ++iter;
      }
      if (iter == collection.end()) {
        iter = collection.begin();
      }
      iter = collection.erase(iter);
    }
    return *collection.begin();
  }
};