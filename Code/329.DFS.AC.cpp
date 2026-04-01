#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    std::vector<std::pair<int, int>> directions{{0,  1},
                                                {0,  -1},
                                                {1,  0},
                                                {-1, 0}};

    int DFS(int row, int column, const vector<vector<int>> &matrix, std::vector<int> *mem) {
        if ((*mem)[row * matrix.front().size() + column]) {
            return (*mem)[row * matrix.front().size() + column];
        }
        (*mem)[row * matrix.front().size() + column] += 1;
        for (const auto &direction : directions) {
            int new_row = row + direction.first;
            int new_column = column + direction.second;
            if (new_row >= 0 && new_row < matrix.size() && new_column >= 0 &&
                new_column < matrix.front().size() && matrix[new_row][new_column] >
                                                      matrix[row][column]) {
                (*mem)[row * matrix.front().size() + column] = std::max((*mem)[row * matrix.front().size() + column],
                                                                        1 + DFS(new_row, new_column, matrix, mem));
            }
        }
        return (*mem)[row * matrix.front().size() + column];
    }

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        std::vector<int> mem(matrix.size() * matrix.front().size(), 0);
        int result = 0;
        for (int row = 0; row < matrix.size(); ++row) {
            for (int column = 0; column < matrix.front().size(); ++column) {
                result = std::max(result, DFS(row, column, matrix, &mem));
            }
        }
        return result;
    }
};