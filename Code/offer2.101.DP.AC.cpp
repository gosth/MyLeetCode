#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        if (nums.size() < 2) {
            return false;
        }
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        int target = sum / 2;
        std::vector<std::vector<bool>> dp(nums.size(), std::vector<bool>(target + 1, false));
        if (nums[0] <= target) {
            dp[0][nums[0]] = 1;
        }
        for (int line = 1; line < nums.size(); ++line) {
            for (int column = 0; column < target + 1; ++column) {
                dp[line][column] = dp[line - 1][column];
                if (nums[line] == column) {
                    dp[line][column] = 1;
                    continue;
                }
                if (nums[line] < column) {
                    dp[line][column] = dp[line][column] || dp[line - 1][column - nums[line]];
                }
            }
        }
        return dp[nums.size() - 1][target];
    }
};

int main() {
    Solution s;
    auto a = std::vector<int>{9, 5};
    cout << s.canPartition(a);
    return 0;
}
