#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:

    int GetMaxArea(const std::vector<int>& heights) {
        std::stack<int> height_stack;
        int max_area = 0;
        height_stack.emplace(-1);
        for (int column = 0; column < heights.size(); ++column) {
            while (!height_stack.empty() && height_stack.top() >= 0 && heights[height_stack.top()] > heights[column]) {
                int cur = height_stack.top();
                height_stack.pop();
                int left = height_stack.top() + 1;
                int right = column - 1;
                max_area = max(max_area, (right - left + 1) * heights[cur]);
            }
            height_stack.emplace(column);
        }
        return max_area;
    }

    int maximalRectangle(vector<string>& matrix) {
        int max_area = 0;
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        for (int line = 0; line < matrix.size(); ++line) {
            std::vector<int> heights(matrix.front().size() + 1, 0);
            for (int column = 0; column < matrix.front().size(); ++column) {
                int height = 0;
                int new_line = line;
                while (new_line >= 0 && matrix[new_line][column] == '1') {
                    ++height;
                    --new_line;
                }
                heights[column] = height;
            }
            max_area = std::max(max_area, GetMaxArea(heights));
        }
        return max_area;
    }
};

int main() {
std::vector<std::vector<char>> matrix{{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
Solution a;
cout << a.maximalRectangle(matrix);
}