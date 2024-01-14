class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    std::set<int> all_data, used_data;
    for (int index = 0; index < isConnected.size(); ++index) {
      all_data.emplace(index);
    }
    int result = 0;
    while (!all_data.empty()) {
      std::deque<int> queue;
      auto start_node = *all_data.begin();
      queue.emplace_back(start_node);
      used_data.emplace(start_node);
      while (!queue.empty()) {
        auto current_node = queue.front();
        queue.pop_front();
        auto& line = isConnected[current_node];
        for (int inner_index = 0; inner_index < isConnected.size(); ++inner_index) {
          if (line[inner_index] == 1) {
            if (used_data.find(inner_index) == used_data.end()) {
              all_data.erase(inner_index);
              used_data.emplace(inner_index);
              queue.emplace_back(inner_index);
            }
          }
        }
      }
      all_data.erase(all_data.begin());
      ++result;
    }
    return result;
  }
};