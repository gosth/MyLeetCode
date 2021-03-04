class Solution {
 public:
  bool DFS(const std::vector<std::vector<char>>& board,
           int current_line,
           int lines,
           int current_column,
           int columns,
           const std::string& word,
           std::vector<std::vector<bool>>* visited) {
    if (word.empty()) {
      return true;
    }
    if (current_line < 0 || current_line >= lines || current_column < 0
        || current_column >= columns) {
      return false;
    }
    if (board[current_line][current_column] != word.front()
        || (*visited)[current_line][current_column]) {
      return false;
    } else {
      (*visited)[current_line][current_column] = true;
      const auto& feature_pattern2 = word.substr(1);
      if (DFS(board, current_line + 1, lines, current_column, columns, feature_pattern2, visited) ||
          DFS(board, current_line - 1, lines, current_column, columns, feature_pattern2, visited) ||
          DFS(board, current_line, lines, current_column + 1, columns, feature_pattern2, visited) ||
          DFS(board, current_line, lines, current_column - 1, columns, feature_pattern2, visited)) {
        return true;
      } else {
        (*visited)[current_line][current_column] = false;
        return false;
      }
    }
    return false;

  }

  bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || board.front().empty() || word.empty()) {
      return false;
    }
    const int lines = board.size(), columns = board.front().size();
    std::vector<std::vector<bool>> visited(lines, std::vector<bool>(columns, false));
    for (int current_line = 0; current_line < lines; ++current_line) {
      for (int current_column = 0; current_column < columns; ++current_column) {
        if (DFS(board,
                current_line,
                lines,
                current_column,
                columns,
                word,
                &visited)) {
          return true;
        }
      }
    }
    return false;
  }
};