#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int RangeDP(const std::vector<int>& nums, int start_index, int end_index) {
        std::vector<int> dp(end_index - start_index + 1, 0);
        dp[0] = nums[start_index];
        dp[1] = std::max(nums[start_index], nums[start_index + 1]);
        for (int index = 2; index < end_index - start_index + 1; ++index) {
            dp[index] = std::max(dp[index - 2] + nums[start_index + index], dp[index - 1]);
        }
        return dp[end_index - start_index];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums.front();
        }
        if (nums.size() == 2) {
            return std::max(nums[0], nums[1]);
        }
        // 如果偷nums[0]，求nums[0]到nums[n - 2]的最大偷窃值；如果不偷nums[0]，求nums[1]到nums[n - 1]的最大偷窃值。两者较大值即为答案。
        return std::max(RangeDP(nums, 0, nums.size() - 2), RangeDP(nums, 1, nums.size() - 1));
    }

};

int main() {
    Solution s;
    std::vector<int> v{1,2,3};
    cout << s.rob(v);
    return 0;
}