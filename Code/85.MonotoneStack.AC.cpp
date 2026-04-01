class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len = heights.size();
        if (len == 0) {
            return 0;
        }
        if (len == 1) {
            return heights[0];
        }
        int res = 0;
        std::vector<int> newHeights(len + 2);
        for (int i = 0; i < heights.size(); ++i) {
            newHeights[i + 1] = heights[i];
        }
        newHeights[len + 1] = 0;
        len += 2;
        heights.swap(newHeights);
        std::stack<int> status;
        status.emplace(0);
        for (int i = 1; i < len; i++) {
            while (heights[i] < heights[status.top()]) {
                int curHeight = heights[status.top()];
                status.pop();
                int curWidth = i - status.top() - 1;
                res = std::max(res, curHeight * curWidth);
            }
            status.emplace(i);
        }
        return res;
    }

    int maximalRectangle(const std::vector<std::vector<char>>& matrix) {
        int result = 0;
        for (int lineIndex = 0; lineIndex < matrix.size(); ++lineIndex) {
            std::vector<int> heights;
            for (int contentIndex = 0; contentIndex < matrix.front().size(); ++contentIndex) {
                int contentValue = 0;
                int curLine = lineIndex, curColumn = contentIndex;
                while (curLine >= 0 && (matrix[curLine][curColumn] == '1')) {
                    ++contentValue;
                    --curLine;
                }
                heights.emplace_back(contentValue);
            }
            result = std::max(result, largestRectangleArea(heights));
        }
        return result;
    }
};