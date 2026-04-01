class Solution {
public:
    string reformat(string s) {
        std::string result;
        std::deque<char> alpha, num;
        for (const auto& item : s) {
            if (item >= '0' && item <= '9') {
                num.emplace_back(item);
            }
            if (item >= 'a' && item <= 'z') {
                alpha.emplace_back(item);
            }
        }
        while (alpha.size() == num.size() + 1) {
            result += alpha.front();
            alpha.pop_front();
            if (!num.empty()) {
                result += num.front();
                num.pop_front();
            }
        }

        while (num.size() == alpha.size() + 1) {
            result += num.front();
            num.pop_front();
            if (!alpha.empty()) {
                result += alpha.front();
                alpha.pop_front();
            }
        }
        if (alpha.size()) {
            if (alpha.size() == num.size()) {
                while (num.size()) {
                    result += num.front();
                    num.pop_front();
                    result += alpha.front();
                    alpha.pop_front();
                }
            }
        }
        return result;
    }
};