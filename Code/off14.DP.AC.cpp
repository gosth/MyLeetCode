class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2) {
            return 0;
        }
        if (2 == n) {
            return 1;
        }
        if (3 == n) {
            return 2;
        }
        std::vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i < n + 1; ++i) {
            for (int j = 1; j <= i - 1; ++j) {
                dp[i] = std::max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[n];
    }
};