class Solution {
public:
    string minNumber(vector<int>& nums) {
        std::string result;
        std::sort(nums.begin(), nums.end(), [](const int num1, const int num2) {
            const std::string& num1String = std::to_string(num1);
            const std::string& num2String = std::to_string(num2);
            return num1String + num2String < num2String + num1String;
        });
        for (const auto& item : nums) {
            result += std::to_string(item);
        }
        return result;
    }
};