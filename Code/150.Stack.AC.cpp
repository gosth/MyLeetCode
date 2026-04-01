
    class Solution {
    public:
        int transfer(const std::string& item) {
            int number = 0;
            if (!item.empty()) {
                int itemIndex = 0;
                bool isPositive = true;
                if (item.front() == sign1.front()) {
                    itemIndex = 1;
                } else if (item.front() == sign2.front()) {
                    itemIndex = 1;
                    isPositive = false;
                }
                for (; itemIndex < item.size(); ++itemIndex) {
                    number = number * 10 + item[itemIndex] - '0';
                }
                if (!isPositive) {
                    number *= -1;
                }
            }
            return number;
        }
        
        int evalRPN(vector<string>& tokens) {
            std::deque<int> stackStore;
            for (const auto& token : tokens) {
                if (std::find(signs.begin(), signs.end(), token) == signs.end()) {
                    const int number = transfer(token);
                    stackStore.emplace_back(number);
                } else {
                    int item1 = stackStore.back();
                    stackStore.pop_back();
                    int item2 = stackStore.back();
                    stackStore.pop_back();
                    int tempResult = 0;
                    if (token == sign1) {
                        tempResult = item2 + item1;
                    } else if (token == sign2) {
                        tempResult = item2 - item1;
                    } else if (token == sign3) {
                        tempResult = item2 * item1;
                    } else if (token == sign4) {
                        tempResult = item2 / item1;
                    }
                    stackStore.emplace_back(tempResult);
                }
            }
            if (!stackStore.empty()) {
                return stackStore.front();
            } else {
                return 0;
            }
        }
        
        const std::string sign1 = "+";
        const std::string sign2 = "-";
        const std::string sign3 = "*";
        const std::string sign4 = "/";

        const std::vector<std::string> signs = {sign1, sign2, sign3, sign4};
    };