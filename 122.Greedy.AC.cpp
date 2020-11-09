class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) {
            return 0;
        }
        int result = 0;
        for (size_t index = 1; index < prices.size(); ++index) {
            const int profit = prices[index] - prices[index - 1];
            if (profit > 0) {
                result += profit;
            }
        }
        return result;
    }
};