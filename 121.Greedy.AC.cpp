class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int maxProfit = 0, minPrice = INT_MAX;
            if (prices.empty()) {
                return maxProfit;
            }
            for (const auto& price : prices) {
                maxProfit = std::max(maxProfit, price - minPrice);
                minPrice = std::min(minPrice, price);
            }
            return maxProfit;
        }
};