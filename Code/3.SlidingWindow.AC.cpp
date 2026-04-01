class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int result = 0;
            if (s.empty()) {
                return result;
            }
            std::map<char, int> mapping;
            int startIndex = 0;
            mapping.emplace(s.front(), 0);
            result = 1;
            for (int index = 1; index < s.size(); ++index) {
                const auto& item = s[index];
                auto iter = mapping.find(item);
                if (iter != mapping.end()) {
                    const int length = index - 1 - startIndex + 1;
                    result = std::max(result, length);
                    const int newStart = iter->second + 1;
                    for (int eraseIndex = startIndex; eraseIndex <= newStart - 1; ++eraseIndex) {
                        mapping.erase(s[eraseIndex]);
                    }
                    startIndex = newStart;
                    mapping.emplace(item, index);
                } else {
                    mapping.emplace(item, index);
                }
            }
            result = std::max(static_cast<int>(s.size() - 1) - startIndex + 1, result);
            return result;
        }
    };