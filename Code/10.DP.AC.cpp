class Solution {
public:
    bool isMatchChar(char input1, char input2) {
        if (input1 == input2 || input2 == '.') {
            return true;
        } else {
            return false;
        }
    }

    bool isMatch(const std::string& s, const std::string& p) {
        std::vector<std::vector<int>> dp(s.size() + 1,
                std::vector<int>(p.size() + 1, 0));
        dp[0][0] = 1;
        for (int patternIndex = 2; patternIndex <= p.size(); ++patternIndex) {
            dp[0][patternIndex] =
                    p[patternIndex - 1] == '*' && dp[0][patternIndex - 2];
        }
        for (int stringIndex = 0; stringIndex < s.size(); ++stringIndex) {
            for (int patternIndex = 0; patternIndex < p.size(); ++patternIndex) {
                if (p[patternIndex] == '*') {
                    dp[stringIndex + 1][patternIndex + 1] = (dp[stringIndex + 1][patternIndex - 1]) ||
                            (isMatchChar(s[stringIndex], p[patternIndex - 1]) && dp[stringIndex][patternIndex + 1]);
                } else {
                    dp[stringIndex + 1][patternIndex + 1] = (isMatchChar(s[stringIndex], p[patternIndex]) &&
                            dp[stringIndex][patternIndex]);
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};