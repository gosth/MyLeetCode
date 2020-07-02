class Solution {
    bool allInclude(std::map<char, int>& info) {
        for (const auto& item : info) {
            if (item.second > 0) {
                return false;
            }
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        std::map<char, int> totalNeed, currentNeed;
        for (const auto& item : t) {
            totalNeed[item] += 1;
        }
        currentNeed = totalNeed;
        int left = 0, right = 0, length = INT_MAX, final_left = -1,
                final_right = -1;
        for (; right < s.size(); ++right) {
            const auto& alpha = s[right];
            if (currentNeed.find(alpha) != currentNeed.end()) {
                currentNeed[alpha] -= 1;
            }
            while (allInclude(currentNeed) && left <= right) {
                if (length > right - left + 1) {

                    length = right - left + 1;
                    final_left = left;
                    final_right = right;
                }
                auto left_index_item = s[left];
                if (totalNeed.find(left_index_item) != totalNeed.end()) {
                    currentNeed[left_index_item] += 1;
                }
                ++left;
            }
        }
        std::string result;
        if (final_left == -1 || final_right == -1) {
            return result;
        }
        for (int i = final_left; i <= final_right; ++i) {
            result += s[i];
        }
        return result;
    }
};