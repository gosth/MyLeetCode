class Solution {
    public:

        std::string addString(const std::string& num1, const std::string& num2) {
            if (num1.empty() || num1 == "0") {
                return num2.empty() ? "0" : num2;
            }
            if (num2.empty() || num2 == "0") {
                return num1.empty() ? "0" : num1;
            }
            int i = num1.size() - 1, j = num2.size() - 1, addBit = 0;
            std::string result;
            while (i >= 0 || j >= 0 || addBit) {
                int a = 0, b = 0;
                if (i >= 0) {
                    a = num1[i] - '0';
                    --i;
                }
                if (j >= 0) {
                    b = num2[j] - '0';
                    --j;
                }
                int tempSum = a + b + addBit;
                result = std::to_string(tempSum % 10) + result;
                addBit = tempSum / 10;
            }
            return result;
        }

        string multiply(string num1, string num2) {
            if (num1 == "0" || num2 == "0") {
                return "0";
            }
            std::vector<std::string> levelSums;
            int addBit = 0;
            for (int i = num2.size() - 1; i >= 0; --i) {
                std::string levelSum;
                int addBit = 0;
                for (int j = num1.size() - 1; j >= 0; --j) {
                    int a = num2[i] - '0';
                    int b = num1[j] - '0';
                    int multiResult = a * b + addBit;
                    levelSum = std::to_string(multiResult % 10) + levelSum;
                    addBit = multiResult / 10;
                }
                if (addBit) {
                    levelSum = std::to_string(addBit) + levelSum;
                }
                for (int round = num2.size() - 1 - i; round > 0; --round) {
                    levelSum += "0";
                }
                levelSums.emplace_back(levelSum);
            }
            std::string result = "0";
            for (const auto& item : levelSums) {
                result = addString(result, item);
            }
            return result;
        }
    };