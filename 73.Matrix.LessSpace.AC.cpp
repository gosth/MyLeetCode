class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return;
        }
        bool haveZeroInFirstColumn = false;
        for (int lineIndex = 0; lineIndex < matrix.size(); ++lineIndex) {
            if (0 == matrix[lineIndex].front()) {
                haveZeroInFirstColumn = true;
                break;
            }
        }
        for (int columnIndex = 0; columnIndex < matrix.front().size(); ++columnIndex) {
            if (0 == matrix[0][columnIndex]) {
                matrix[0][0] = 0;
                break;
            }
        }
        // 视频新主题
        for (int lineIndex = 1; lineIndex < matrix.size(); ++lineIndex) {
            for (int columnIndex = 1; columnIndex < matrix.front().size(); ++columnIndex) {
                if (0 == matrix[lineIndex][columnIndex]) {
                    matrix[lineIndex][0] = 0;
                    matrix[0][columnIndex] = 0;
                }
            }
        }
        for (int lineIndex = 1; lineIndex < matrix.size(); ++lineIndex) {
            if (0 == matrix[lineIndex].front()) {
                for (int columnIndex = 1; columnIndex < matrix.front().size(); ++columnIndex) {
                    matrix[lineIndex][columnIndex] = 0;
                }
            }
        }

        for (int columnIndex = 1; columnIndex < matrix.front().size(); ++columnIndex) {
            if (0 == matrix[0][columnIndex]) {
                for (int lineIndex = 1; lineIndex < matrix.size(); ++lineIndex) {
                    matrix[lineIndex][columnIndex] = 0;
                }
            }
        }
        if (0 == matrix[0][0]) {
            for (int columnIndex = 1; columnIndex < matrix.front().size(); ++columnIndex) {
                matrix[0][columnIndex] = 0;
            }
        }
        if (haveZeroInFirstColumn) {
            for (int lineIndex = 0; lineIndex < matrix.size(); ++lineIndex) {
                matrix[lineIndex][0] = 0;
            }
        }
    }
};
