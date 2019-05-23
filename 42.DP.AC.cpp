class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        if (height.empty()) {
            return result;
        }
        vector<int> leftMax(height.size()), rightMax(height.size());
        leftMax[0] = height.front();
        for (int i = 1; i < height.size(); ++i){
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        rightMax[height.size() - 1] = height.back();
        for (int i = height.size() - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        for (int i = 0; i < height.size(); ++i) {
            result += min(leftMax[i], rightMax[i]) - height[i];
        }
        return result;
    }
};