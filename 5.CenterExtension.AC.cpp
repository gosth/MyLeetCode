class Solution {
    std::string getCurrentLongestPalindrome(const std::string& original, int left, int right) {
        while (left - 1 >= 0 && right + 1 < original.size() && original[left - 1] == original[right + 1]) {
            --left;
            ++right;
        }
        return original.substr(left, right - left + 1);
    }

public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return s;
        }
        std::string result = s.substr(0, 1);
        for (int i = 0; i < s.size(); ++i) {
            const auto& tempResult = getCurrentLongestPalindrome(s, i, i);
            if (tempResult.size() > result.size()) {
                result = tempResult;
            }
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                const auto& tempResult = getCurrentLongestPalindrome(s, i, i + 1);
                if (tempResult.size() > result.size()) {
                    result = tempResult;
                }
            }
        }
        return result;

    }
};