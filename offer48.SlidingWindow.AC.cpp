class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int32_t firstIndex = 0, secondIndex = 0;
        std::unordered_map<char, int32_t> mapping;
        int32_t maxLength = 0;
        for (; secondIndex < s.size(); ++secondIndex) {
            const auto& item = s[secondIndex];
            auto iter = mapping.find(item);
            if (iter == mapping.end()) {
                mapping.emplace(item, secondIndex);
            } else {
                maxLength = std::max(maxLength, secondIndex - firstIndex);
                int32_t firstIndex2 = iter->second + 1;
                for (int32_t eraseIndex = firstIndex; eraseIndex < firstIndex2; ++eraseIndex) {
                    mapping.erase(s[eraseIndex]);
                }
                mapping.emplace(item, secondIndex);
                firstIndex = firstIndex2;
            }
        }
        maxLength = std::max(maxLength, static_cast<int32_t>(s.size()) - 1 - firstIndex + 1);
        return maxLength;
    }
};