class Solution {
public:
    int minCount(vector<int>& coins) {
        int result = 0;
        for (const auto& item : coins) {
            result += item / 2;
            result += item % 2;
        }
        return result;
    }
};