#include <iostream>
#include <set>
#include <vector>

using namespace std;


class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (const auto &item : nums) {
            sum += item;
        }
        if (sum % 2 == 1) {
            return false;
        }
        int target = sum / 2;
        // dp[i][j] 前0-i号物品中任选几个，是否能装满容量为j的背包
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(target + 1, 0));
        if (nums.front() <= target) {
            dp[0][nums.front()] = 1;
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                if (nums[i] == j) {
                    dp[i][j] = 1;
                    continue;
                }
                if (dp[i - 1][j]) {
                    dp[i][j] = 1;
                    continue;
                }
                if (j - nums[i] >= 0) {
                    dp[i][j] = dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[nums.size() - 1][target];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
