class Solution {
public:
    string reverseWords(string s) {
        if (s.empty()) {
            return std::string();
        }
        bool flag = false;
        size_t index = 0;
        int length = 0;
        std::vector<std::string> words;
        std::string result;
        for (size_t i = 0; i < s.size(); ++i) {
            const auto& item = s[i];
            if (item != ' ') {
                if (!flag) {
                    flag = true;
                    index = i;
                    length = 0;
                }
                ++length;
            } else {
                if (!flag) {
                    continue;
                } else {
                    flag = false;
                    words.emplace_back(s.substr(index, length));
                }
            }
        }
        if (s.back() != ' ') {
            words.emplace_back(s.substr(index, length));
        }
        while (!words.empty()) {
            result += words.back() + " ";
            words.pop_back();
        }
        if (!result.empty()) {
            result = result.substr(0, result.size() - 1);
        }
        return result;
    }
};