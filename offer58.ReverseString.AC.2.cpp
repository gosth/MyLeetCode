class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return "";
        }
        int start_index = 0,
                end_index = s.size() - 1;
        while (start_index < s.size() &&
               ' ' == s[start_index]) {
            ++start_index;
        }
        while (end_index >= 0 &&
               ' ' == s[end_index]) {
            --end_index;
        }
        if (start_index == end_index) {
            return s.substr(start_index, 1);
        } else if (start_index > end_index) {
            return "";
        }
        s = s.substr(
                start_index, end_index - start_index + 1);
        for (auto iter = s.begin() + 1; iter != s.end();) {
            if (' ' == *(iter - 1) && ' ' == *(iter)) {
                iter = s.erase(iter - 1);
            } else {
                ++iter;
            }
        }
        std::reverse(s.begin(), s.end());
        auto start_iter = s.begin();
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            if (*iter == ' ') {
                std::reverse(start_iter, iter);
                start_iter = iter + 1;
            }
        }
        std::reverse(start_iter, s.end());
        return s;
    }
};