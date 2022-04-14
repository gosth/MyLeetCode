#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        std::vector<std::vector<int64_t>> dp(s.size() + 1, std::vector<int64_t>(t.size() + 1,0));
        for (int j = 0; j < t.size() + 1; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 0; i < s.size() + 1; ++i) {
            dp[i][0] = 1;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= t.size(); ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % INT_MAX;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};