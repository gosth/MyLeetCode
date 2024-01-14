class RecentCounter {
public:
    RecentCounter() {

    }
    
    int ping(int t) {
      data.emplace_back(t);
      int target_t = t - 3000;
      auto iter = std::lower_bound(data.begin(), data.end(), target_t);
      if (iter != data.end()) {
        return data.end() - iter;
      }
      return 0;
    }

    std::vector<int> data;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */