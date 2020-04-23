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
        };