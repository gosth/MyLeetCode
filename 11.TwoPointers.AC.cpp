class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxValue = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left != right) {
            int currentHeight = std::min(height[left], height[right]);
            int length = right - left;
            maxValue = std::max(maxValue, currentHeight * length);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return maxValue;
    }
};