class Solution {
public:
    bool isPalindrome(string s) {
        std::string processed_data;
        for (const auto& item : s) {
            if (std::isalnum(item)) {
                processed_data += std::tolower(item);
            }
        }
        std::string reversed_data(processed_data.rbegin(), processed_data.rend());
        return processed_data == reversed_data;
    }
};