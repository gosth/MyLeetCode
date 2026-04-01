class Solution {
    public:
        bool checkInclusion(string s1, string s2) {
            if (s1.empty()) {
                return true;
            }
            std::map<char, int> needed;
            for (const auto& item : s1) {
                needed[item] += 1;
            }
            int left = 0, right = 0;
            while (right < s2.size()) {
                const auto& item = s2[right];
                ++right;
                needed[item] -= 1;
                while (left < right && needed[item] < 0) {
                    const auto& lastItem = s2[left];
                    needed[lastItem] += 1;
                    ++left;
                }
                if (right - left == s1.size()) {
                    return true;
                }
            }
            return false;
        }
    };