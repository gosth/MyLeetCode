class Solution {
public:
    int longestPalindrome(string s) {
        int result = 0;
        bool hasOddNumber = false;
        std::map<char, int> dict;
        for (const auto& item : s) {
            dict[item] += 1;
        }
        for (const auto& item : dict) {
            result += item.second / 2;
            if (item.second % 2 == 1) {
                hasOddNumber = true;
            }
        }
        result *= 2;
        if (hasOddNumber) {
            result += 1;
        }
        return result;
    }
};