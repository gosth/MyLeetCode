class Solution {
public:
    bool isPalindrome(string s) {
        bool result = true;
        if (s.empty()) {
            return true;
        }
        string::size_type begin = 0;
        string::size_type end = s.size() - 1;
        while (begin < end) {
            if (s[begin] >= 'A' && s[begin] <= 'Z') {
                s[begin] = s[begin] - 'A' + 'a';
            } else if (!((s[begin] >= '0' && s[begin] <= '9') || (s[begin] >= 'a' && s[begin] <= 'z'))) {
                ++begin;
                continue;
            }
            if (s[end] >= 'A' && s[end] <= 'Z') {
                s[end] = s[end] - 'A' + 'a';
            } else if (!((s[end] >= '0' && s[end] <= '9') || (s[end] >= 'a' && s[end] <= 'z'))) {
                --end;
                continue;
            }
            if (s[begin] != s[end]) {
                result = false;
                break;
            }
            ++begin;
            --end;
        }
        return result;
    }
};