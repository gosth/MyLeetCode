#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        if (height.empty()) {
            return result;
        }
        for (size_t i = 1; i < height.size() - 1; ++i) {
            int leftMax = 0, rightMax = 0;
            for (int j = i; j >= 0; --j) { //找到i左侧最大值 如果用size_t这里会下溢
                leftMax = max(leftMax, height[j]);
            }
            for (size_t j = i; j < height.size(); ++j) { //找到i右侧最大值
                rightMax = max(rightMax, height[j]);
            }
            result += min(leftMax, rightMax) - height[i];
        }
        return result;
    }
};

int main() {
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution b;
    cout << b.trap(a) << endl;
}