class Solution {
public:
    int characterReplacement(string s, int k) {
        // maxCount是用来计算窗口的maxcount，而不是重复字符的maxcount
        // Since we are only interested in the longest valid substring, our sliding windows need not shrink, even if a window may cover an invalid substring. We either grow the window by appending one char on the right, or shift the whole window to the right by one. And we only grow the window when the count of the new char exceeds the historical max count (from a previous window that covers a valid substring).
        // That is, we do not need the accurate max count of the current window; we only care if the max count exceeds the historical max count; and that can only happen because of the new char.
        int maxCount = 0, result = 0, left = 0, right = 0;
        std::vector<int> count(26, 0);
        for (; right < s.size(); ++right) {
            count[s[right] - 'A'] += 1;
            maxCount = std::max(maxCount, count[s[right] - 'A']);
            if (right - left + 1 > maxCount + k) {
                count[s[left] - 'A'] -= 1;
                ++left;
            }
            result = std::max(result, right - left + 1);
        }
        return result;
    }
};