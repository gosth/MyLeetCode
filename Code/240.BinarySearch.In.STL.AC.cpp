class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& line : matrix) {
            if (std::binary_search(line.begin(), line.end(), target)) {
                return true;
            };
        }
        return false;
    }
};