  class Solution {
        void initial() {
            mapping['2'] = std::vector<std::string>{"a","b","c"};
            mapping['3'] = std::vector<std::string>{"d","e","f"};
            mapping['4'] = std::vector<std::string>{"g","h","i"};
            mapping['5'] = std::vector<std::string>{"j","k","l"};
            mapping['6'] = std::vector<std::string>{"m","n","o"};
            mapping['7'] = std::vector<std::string>{"p","q","r", "s"};
            mapping['8'] = std::vector<std::string>{"t","u","v"};
            mapping['9'] = std::vector<std::string>{"w","x","y", "z"};
        }
    public:
        vector<string> letterCombinations(string digits) {
            std::vector<std::string> result;
            initial();
            for (const auto& item : digits) {
                const auto& letters = mapping[item];
                if (result.empty()) {
                    result.insert(result.end(), letters.begin(), letters.end());
                } else {
                    std::vector<std::string> newResult;
                    for (const auto& letter : letters) {
                        std::vector<std::string> newResults2 = result;
                        for (auto& tempResult : newResults2) {
                            tempResult += letter;
                        }
                        newResult.insert(newResult.end(), newResults2.begin(), newResults2.end());
                    }
                    result = newResult;
                }
            }
            return result;
        }

    private:
        std::map<char, std::vector<std::string>> mapping;
    };