    class Solution {
    public:
        int maxCoins(vector<int>& nums) {

            if (nums.size() == 0) {
                return 0;
            }
            vector<int> nums2;
            nums2.push_back(1);
            nums2.insert(nums2.end(), nums.begin(), nums.end());
            nums2.push_back(1);
            vector<vector<int>> dp(nums2.size(), vector<int>(nums2.size(), 0));
            for (int i = 2; i < nums2.size(); ++i) {
                for (int start = 0; start < nums2.size() - i; ++start) {
                    int end = start + i;
                    for (int k = start + 1; k < end; ++k) {
                        dp[start][end] = std::max(dp[start][end],
                                dp[start][k] + dp[k][end] + nums2[start] * nums2[end] * nums2[k]);
                    }
                }
            }
            return dp[0][nums2.size() - 1];
        }
    };