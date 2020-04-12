class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        const bool isHeadMatch = (!s.empty() && (s.front() == p.front() || p.front() == '.'));
        if (p.length() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (isHeadMatch && isMatch(s.substr(1), p));
        } else if (isHeadMatch) {
            return isMatch(s.substr(1), p.substr(1));
        } else {
            return false;
        }
    }
};