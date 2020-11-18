 class Solution {
    public:
        string removeDuplicateLetters(string s) {
            if (s.size() < 2) {
                return s;
            }
            bool used[26];
            for (const auto& item : s) {
                used[item - 'a'] = false;
            }
            std::vector<int> lastApperance(26, -1);
            for (size_t index = 0; index < s.size(); ++index) {
                lastApperance[s[index] - 'a'] = index;
            }
            std::stack<char> stackStore;
            for (size_t index = 0; index < s.size(); ++index) {
                const char item = s[index];
                if (used[item - 'a']) {
                    continue;
                }
                while (!stackStore.empty() && stackStore.top() > item &&
                        lastApperance[stackStore.top() - 'a'] >= index) {
                    auto top = stackStore.top();
                    stackStore.pop();
                    used[top - 'a'] = false;
                }
                stackStore.emplace(item);
                used[item - 'a'] = true;
            }
            std::string result;
            while (!stackStore.empty()) {
                result += stackStore.top();
                stackStore.pop();
            }
            std::reverse(result.begin(), result.end());
            return result;
        }
    };