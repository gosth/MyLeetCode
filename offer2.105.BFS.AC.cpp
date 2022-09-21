class Solution {
 public:
  void BFS(const std::vector<std::vector<int>>& grid,
           std::set<std::pair<int, int>>* uniq_sign,
           std::deque<std::pair<int, int>>* data_queue,
           int* result,
           int* current_area) {
    while (!data_queue->empty()) {
      auto current_feature = data_queue->front();
      (*current_area) += 1;
      data_queue->pop_front();
      for (const auto& gray_sign : directions) {
        int line = current_feature.first + gray_sign.first;
        int column = current_feature.second + gray_sign.second;
        if (line >= 0 && line < grid.size() && column >= 0 && column < grid.front().size() &&
            grid[line][column] &&
            uniq_sign->find(std::make_pair(line, column)) == uniq_sign->end()) {
          data_queue->emplace_back(line, column);
          uniq_sign->emplace(line, column);
        }
      }
      (*result) = std::max((*result), (*current_area));
    }
  }
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid.front().empty()) {
      return 0;
    }
    int result = 0;
    std::deque<std::pair<int, int>> data_queue;
    std::set<std::pair<int, int>> uniq_sign;
    for (int line = 0; line < grid.size(); ++line) {
      for (int column = 0; column < grid.front().size(); ++column) {
        if (1 == grid[line][column] &&
            uniq_sign.find(std::make_pair(line, column)) == uniq_sign.end()) {
          data_queue.clear();
          data_queue.emplace_back(line, column);
          uniq_sign.emplace(line, column);
          int current_area = 0;
          BFS(grid, &uniq_sign, &data_queue, &result, &current_area);
        }
      }
    }
    return result;
  }
  std::vector<std::pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};