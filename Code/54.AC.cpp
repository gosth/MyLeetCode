class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::vector<int> result;
        if (matrix.empty()) {
            return result;
        }
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix.front().size() - 1;
        while (1) {
            for (int index = left; index <= right; ++index) {
                result.emplace_back(matrix[up][index]);
            }
            if (++up > down) {
                break;
            }
            for (int index = up; index <= down; ++index) {
                result.emplace_back(matrix[index][right]);
            }
            if (--right < left) {
                break;
            }
            for (int index = right; index >= left; --index) {
                result.emplace_back(matrix[down][index]);
            }
            if (--down < up) {
                break;
            }
            for (int index = down; index >= up; --index) {
                result.emplace_back(matrix[index][left]);
            }
            if (++left > right) {
                break;
            }
        }
        return result;
    }
};