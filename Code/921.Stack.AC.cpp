class Solution {
public:
    int minAddToMakeValid(string S) {
        std::deque<char> stackStore;
        for (const auto& item : S) {
            if (item == '(') {
                stackStore.emplace_back(item);
            } else {
                if (!stackStore.empty() && stackStore.back() == '(') {
                    stackStore.pop_back();
                } else {
                    stackStore.emplace_back(item);
                }
            }
        }
        return stackStore.size();
    }
};