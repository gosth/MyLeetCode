class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    std::vector<int> course_order;
    if (prerequisites.empty()) {
      for (int index = 0; index < numCourses; ++index) {
        course_order.emplace_back(index);
      }
      return course_order;
    }
    std::unordered_map<int, int> in_degree;
    for (int index = 0; index < numCourses; ++index) {
      in_degree[index] = 0;
    }
    std::unordered_map<int, std::unordered_set<int>> neighbors;
    for (const auto& item : prerequisites) {
      ++in_degree[item.front()];
      neighbors[item.back()].emplace(item.front());
    }
    while (true) {
      int in_degree_size = in_degree.size();
      for (auto iter = in_degree.begin(); iter != in_degree.end();) {
        // 入度为0
        if (iter->second == 0) {
          if (auto iter_2 = neighbors.find(iter->first); iter_2 != neighbors.end()) {
            for (auto& neighbor_node : iter_2->second) {
              // 邻接结点入度减一
              --in_degree[neighbor_node];
            }
          }
          course_order.emplace_back(iter->first);
          iter = in_degree.erase(iter);
        } else {
          ++iter;
        }
      }
      if (in_degree.empty()) {
        return course_order;
      }
      if (in_degree_size == in_degree.size()) {
        return {};
      }
    }
    return {};
  }
};