   class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int maxProfit = 0;
            if (prices.empty()) {
                return maxProfit;
            }
            for (int index = 0; index < prices.size() - 1; ++index) {
                for (int index2 = index + 1; index2 < prices.size(); ++index2) {
                    maxProfit = std::max(maxProfit, prices[index2] - prices[index]);
                }
            }
            return maxProfit;
        }
    };
