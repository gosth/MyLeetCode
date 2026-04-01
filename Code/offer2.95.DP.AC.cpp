#include <iostream>

using namespace std;



class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int text1_length = text1.size(), text2_length = text2.size();
        std::vector<std::vector<int>> dp(text1_length + 1, std::vector<int>(text2_length + 1, 0));
        for (int i = 1; i <= text1_length; ++i) {
            for (int j = 1; j <= text2_length; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1_length][text2_length];
    }
};
