class NumMatrix {
 public:
  NumMatrix(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix.front().empty()) {
      return;
    }
    prefix_sums_.resize(matrix.size(), std::vector<int>(matrix.front().size(), 0));
    prefix_sums_[0][0] = matrix[0][0];
    for (int line = 1; line < matrix.size(); ++line) {
      prefix_sums_[line][0] = prefix_sums_[line - 1][0] + matrix[line][0];
    }
    for (int line = 0; line < matrix.size(); ++line) {
      for (int column = 1; column < matrix.front().size(); ++column) {
        int prefix_sum = prefix_sums_[line][column - 1];
        for (int inner_line = 0; inner_line <= line; ++inner_line) {
          prefix_sum += matrix[inner_line][column];
        }
        prefix_sums_[line][column] = prefix_sum;
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int result = prefix_sums_[row2][col2];
    result -= col1 >= 1 ? prefix_sums_[row2][col1 - 1] : 0;
    result -= row1 >= 1 ? prefix_sums_[row1 - 1][col2] : 0;
    result += (row1 >= 1 && col1 >= 1) ? prefix_sums_[row1 - 1][col1 - 1] : 0;
    return result;
  }

 private:
  std::vector<std::vector<int>> prefix_sums_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */