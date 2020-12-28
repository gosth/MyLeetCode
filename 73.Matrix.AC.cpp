class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return;
        }
        std::set<int> lines, columns;
        for (int lineIndex = 0; lineIndex < matrix.size(); ++lineIndex) {
            for (int columnIndex = 0; columnIndex < matrix.front().size(); ++columnIndex) {
                if (0 == matrix[lineIndex][columnIndex]) {
                    lines.emplace(lineIndex);
                    columns.emplace(columnIndex);
                }
            }
        }
        for (const auto& lineIndex : lines) {
            for (int columnIndex = 0; columnIndex < matrix.front().size(); ++columnIndex) {
                matrix[lineIndex][columnIndex] = 0;
            }
        }
        for (const auto& columnIndex : columns) {
            for (int lineIndex = 0; lineIndex < matrix.size(); ++lineIndex) {
                matrix[lineIndex][columnIndex] = 0;
            }
        }
    }
};