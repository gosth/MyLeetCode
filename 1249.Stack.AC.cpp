class Solution {
public:
    string minRemoveToMakeValid(string s) {
        if (s.empty()) {
            return std::string();
        }
        std::deque<size_t> stackStore;
        for (size_t index = 0; index < s.size(); ++index) {
            const auto& item = s[index];
            if (item == '(') {
                stackStore.emplace_back(index);
            } else if (item == ')') {
                if (!stackStore.empty() && s[stackStore.back()] == '(') {
                    stackStore.pop_back();
                } else {
                    stackStore.emplace_back(index);
                }
            }
        }
        while(!stackStore.empty()) {
            s.erase(stackStore.back(), 1);
            stackStore.pop_back();
        }
        return s;
    }
};