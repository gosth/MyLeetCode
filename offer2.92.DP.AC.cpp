#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int minFlipsMonoIncr(string s) {
        /** 定义子串substr的下标范围为[0,i]
        * dp[i][j]定义为：子串sub翻转后且下标i项值为j时的最小翻转次数。其中j为0或1。
        **/
        /** 状态转移方程
        * dp[i][0] = dp[i - 1][0] + (s[i] == '0' ? 0 : 1)
        * dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (s[i] == '1' ? 0 : 1)
        * 最后的结果是min(dp[s.size() - 1][0], dp[s.size() - 1][1])
        **/
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(2, 0));
        if (s.front() == '0') {
            dp[0][0] = 0;
            dp[0][1] = 1;
        } else {
            // s.front() == '1'
            dp[0][0] = 1;
            dp[0][1] = 0;
        }
        for (int i = 1; i < s.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + (s[i] == '0' ? 0 : 1);
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + (s[i] == '1' ? 0 : 1);
        }
        return std::min(dp[s.size() - 1][0], dp[s.size() - 1][1]);
    }
};

int main() {
    Solution s;
    std::vector<int> a{1, 1, 1, 2, 2, 3333};
    auto result = s.topKFrequent(a, 2);
    cout << "result=" << endl;
    for (const auto& item : result) {
        cout << item << endl;
    }
}
