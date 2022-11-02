class Solution {
public:
    int DFS(int line,
            int column,
            const std::vector<std::vector<int>>& matrix,
            std::vector<std::vector<int>>* memo) {
        if ((*memo)[line][column]) {
            return (*memo)[line][column];
        }
        int step = 1;
        for (const auto& item : directions) {
            int new_line = line + item.first;
            int new_column = column + item.second;
            if (new_line >= 0 && new_line < matrix.size() && new_column >= 0 &&
            new_column < matrix.front().size() && matrix[new_line][new_column] > matrix[line][column]) {
                step = std::max(step, DFS(new_line, new_column, matrix, memo) + 1);
            }
        }
        (*memo)[line][column] = step;
        return step;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int max_value = 0;
        std::vector<std::vector<int>> memo(matrix.size(),
                                           std::vector<int>(matrix.front().size(), 0));
        for (int line = 0; line < matrix.size(); ++line) {
            for (int column = 0; column < matrix.front().size(); ++column) {
                max_value = std::max(max_value, DFS(line, column, matrix, &memo));
            }
        }
        return max_value;
    }
    std::vector<std::pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};