class Solution {
public:
    bool matchHeadSubString(const std::string& s, const std::string& pattern) {
        if (s.size() < pattern.size()) {
            return false;
        }
        for (int index = 0; index < pattern.size(); ++index) {
            if (s[index] != pattern[index]) {
                return false;
            }
        }
        return true;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        std::set<char> originalSet, patternSet;
        for (const auto& item : s) {
            originalSet.emplace(item);
        }
        for (const auto& pattern : wordDict) {
            for (const auto& item : pattern) {
                patternSet.emplace(item);
            }
        }
        for (const auto& item : originalSet) {
            if (patternSet.find(item) == patternSet.end()) {
                return false;
            }
        }
        for (const auto& word : wordDict) {
            if (matchHeadSubString(s, word)) {
                const std::string& newString = s.substr(word.size());
                if (newString.empty()) {
                    return true;
                } else {
                    if (wordBreak(newString, wordDict)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};