class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        std::vector <std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));
        std::string result;
        for (int length = 1; length <= s.size(); ++length) {
            for (int i = 0; i + length - 1 < s.size(); ++i) {
                int j = i + length - 1;
                if (i == j) {
                    dp[i][j] = 1;
                } else if (j - i == 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                    }
                } else {
                    dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                }
                if (dp[i][j] && length > result.size()) {
                    result = s.substr(i, length);
                }
            }
        }
        return result;
    }
};