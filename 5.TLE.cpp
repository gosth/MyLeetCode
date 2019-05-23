class Solution {
public:
    bool isPalindromeString(const string& nowString) {
        size_t end = nowString.size() / 2;
        for (size_t i = 0; i < end; ++i) {
             if (nowString[i] != nowString[nowString.size() - 1 - i]) {
                 return false;
             }
        }
        return true;
    }
    string longestPalindrome(string s) {
        size_t longestLength = s.size();
        size_t begin = 0;
        if (s.empty()) {
            return s;
        }
        while (longestLength != 1) {
            const string& nowString = s.substr(begin, longestLength);
            if (isPalindromeString(nowString)) {
                return nowString;
            } else {
                if (begin + longestLength == s.size()) {
                    begin = 0;
                    --longestLength;
                } else {
                    ++begin;
                }
            }
        }
        return s.substr(0, 1);
    }
};