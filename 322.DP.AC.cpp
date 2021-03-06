class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		std::vector<int> dp(amount + 1, -1);
		dp[0] = 0;
		for (int i = 0; i <= amount; ++i) {
			for (const auto& coin : coins) {
				if (i >= coin && dp[i - coin] != -1) {
					if (dp[i] > dp[i - coin] + 1 || dp[i] == -1) {
						dp[i] = dp[i - coin] + 1;
					}
				}
			}
		}
		return dp[amount];
	}
};