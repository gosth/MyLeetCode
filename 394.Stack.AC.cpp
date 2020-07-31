class Solution {
public:
    string decodeString(string s) {
        std::string result;
        if (s.empty()) {
            return result;
        }
        std::deque<char> stackStore;
        for (const auto& item : s) {
            if (item != ']') {
                stackStore.emplace_back(item);
            } else {
                std::string singlePart, allPart;
                while (!stackStore.empty()) {
                    const auto item3 = stackStore.back();
                    stackStore.pop_back();
                    if (item3 == '[') {
                        int count = 0;
                        std::string count2;
                        while (!stackStore.empty() && stackStore.back() >= '0' && stackStore.back() <= '9') {
                            count2 = count2 + stackStore.back();
                            stackStore.pop_back();
                        }
                        std::reverse(count2.begin(), count2.end());
                        for (const auto& num : count2) {
                            count = count * 10 + num - '0';
                        }
                        std::reverse(singlePart.begin(), singlePart.end());
                        for (int index = 0; index < count; ++index) {
                            allPart = allPart + singlePart;
                        }

                        for (const auto& item2 : allPart) {
                            stackStore.emplace_back(item2);
                        }
                        break;
                    } else {
                        singlePart = singlePart + item3;
                    }
                }
            }
        }
        for (const auto& item : stackStore) {
            result = result + item;
        }
        return result;
    }
};