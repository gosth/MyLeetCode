class Solution {
 public:
  void BFS(const std::vector<std::vector<int>>& mat,
           std::vector<std::vector<int>>* result,
           std::vector<std::vector<int>>* visited,
           std::deque<std::pair<int, int>>* queue) {
    int distance = 0;
    auto queue_size = queue->size();
    while (queue_size) {
      ++distance;
      for (int index = 0; index < queue_size; ++index) {
        auto current = queue->front();
        for (const auto& direction : directions_) {
          int current_line = current.first + direction.first;
          int current_column = current.second + direction.second;
          if (current_line >= 0 && current_line < mat.size() && current_column >= 0 &&
              current_column < mat.front().size() && !(*visited)[current_line][current_column]) {
            if (mat[current_line][current_column]) {
              (*result)[current_line][current_column] = distance;
              queue->emplace_back(current_line, current_column);
            }
            (*visited)[current_line][current_column] = 1;
          }
        }
        queue->pop_front();
      }
      queue_size = queue->size();
    }
  }

  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    // result
    std::vector<std::vector<int>> result(mat.size(), std::vector<int>(mat.front().size(), 0));
    std::vector<std::vector<int>> visited(mat.size(), std::vector<int>(mat.front().size(), 0));
    std::deque<std::pair<int, int>> queue;
    for (int line_index = 0; line_index < mat.size(); ++line_index) {
      for (int column_index = 0; column_index < mat[line_index].size(); ++column_index) {
        if (!mat[line_index][column_index]) {
          result[line_index][column_index] = 0;
          visited[line_index][column_index] = 1;
          queue.emplace_back(line_index, column_index);
        }
      }
    }
    BFS(mat, &result, &visited, &queue);
    return result;
  }

 private:
  std::vector<std::pair<int, int>> directions_{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
};