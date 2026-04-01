class Solution {
public:
    vector <vector<string>> partition(string s) {
        std::vector <std::vector<std::string>> results;
        std::vector <std::string> currentResult;
        splitPalindrome(&results, currentResult, s);
        return results;
    }

    bool isPalindrome(std::string s) {
        bool result = true;
        if (s.empty()) {
            return true;
        }
        string::size_type begin = 0;
        string::size_type end = s.size() - 1;
        while (begin < end) {
            if (s[begin] != s[end]) {
                result = false;
                break;
            }
            ++begin;
            --end;
        }
        return result;
    }

    void
    splitPalindrome(std::vector <std::vector<std::string>>* results,
            const std::vector <std::string>& currentResult,
            const std::string& value) {
        if (value.empty()) {
            results->emplace_back(currentResult);
            return;
        }
        for (size_t i = 1; i <= value.size(); ++i) {
            const auto& currentVal = value.substr(0, i);
            if (isPalindrome(currentVal)) {
                auto tempFeature = currentResult;
                tempFeature.emplace_back(currentVal);
                std::string newValue;
                if (i < value.size()) {
                    newValue = value.substr(i);
                }
                splitPalindrome(results, tempFeature, newValue);
            }
        }
    }
};