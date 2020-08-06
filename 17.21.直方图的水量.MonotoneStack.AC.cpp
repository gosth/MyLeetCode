class Solution {
public:
    int trap(vector<int>& height) {
        std::deque<size_t> stackStore;
        int result = 0;
        if (height.empty()) {
            return result;
        }
        for (size_t index = 0; index < height.size(); ++index) {
            while (!stackStore.empty() && height[index] > height[stackStore.back()]) {
                int currentHeight = height[stackStore.back()];
                stackStore.pop_back();
                if (stackStore.empty()) {
                    break;
                }
                const int leftBound = stackStore.back();
                const int rightBound = index;
                int calcHeight = std::min(height[leftBound], height[rightBound]) - currentHeight;
                int length = rightBound - leftBound - 1;
                result += calcHeight * length;
            }
            stackStore.emplace_back(index);
        }
        return result;
    }
};