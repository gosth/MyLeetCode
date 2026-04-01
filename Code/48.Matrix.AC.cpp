class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int count = matrix.size();
        if (count <= 1) {
            return;
        }
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 1 + i; j < count; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for (auto& line : matrix) {
            std::reverse(line.begin(), line.end());
        }
    }
};