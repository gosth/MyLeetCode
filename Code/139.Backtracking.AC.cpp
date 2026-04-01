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
        if (notMatch.find(s) != notMatch.end()) {
            return false;
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
        notMatch.emplace(s);
        return false;
    }

    std::set<std::string> notMatch;
};