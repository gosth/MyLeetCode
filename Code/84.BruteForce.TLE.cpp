#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int curHeightMaxArea(const vector<int>& heights, const int height) {
        int maxLength = 0, length = 0;
        for (size_t i = 0; i < heights.size(); ++i) {
            if (heights[i] >= height) {
                ++length;
            } else {
                maxLength = maxLength > length ? maxLength : length;
                length = 0;
            }
        }
        maxLength = maxLength > length ? maxLength : length;
        return maxLength * height;
    }
    int maxArea(const vector<int>& heights, int maxHeight) {
        int area = 0;
        for (int height = 1; height <= maxHeight; ++height) {
            int curArea = curHeightMaxArea(heights, height);
            area = area > curArea ? area : curArea;
        }
        return area;
    }

    int largestRectangleArea(vector<int>& heights) {
        int maxHeight = 0, area = 0;
        for (size_t i = 0; i < heights.size(); ++i) {
            if (heights[i] > maxHeight) {
                maxHeight = heights[i];
            }
        }
        return area = maxArea(heights, maxHeight);
    }
};

int main() {
    vector<int> a = {0,0,0,0,0,0,0,0,2147483647};
    Solution b;
    cout << b.largestRectangleArea(a) << endl;
}