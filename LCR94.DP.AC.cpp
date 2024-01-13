class Solution {
public:
    bool IsHuiWen(const std::string& temp) {
        if (temp.size() == 1) {
            return true;
        }
        int left_index = temp.size() / 2 - 1;
        int right_index = temp.size() % 2 == 0 ? temp.size() / 2 : temp.size() / 2 + 1;
        for (; left_index >= 0; --left_index, ++right_index) {
            if (temp[left_index] != temp[right_index]) {
                return false;
            }
        }
        return true;
    }

    int minCut(string s) {
        std::vector<int> dp(s.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < s.size(); ++i) {
            const std::string& temp = s.substr(0, i + 1);
            if (IsHuiWen(temp)) {
                dp[i] = 0;
                continue;
            }
            // 枚举分割点，分割点为j后面
            for (int j = 0; j <= i - 1; ++j) {
                const std::string& temp2 = s.substr(j + 1, i - (j + 1) + 1);
                if (IsHuiWen(temp2)) {
                    dp[i] = std::min(dp[i], dp[j]);
                }
            }
            dp[i] += 1;
        }
        return dp[s.size() - 1];
    }
};