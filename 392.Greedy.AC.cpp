class Solution {
public:
    bool isSubsequence(string s, string t) {
        int matchCount = 0;
        size_t i = 0, j = 0;
        for (; i < s.size(); ++i) {
            for (; j < t.size(); ++j) {
                if (s[i] == t[j]) {
                    ++matchCount;
                    ++j;
                    break;
                }
            }
        }
        return matchCount == s.size();
    }
};