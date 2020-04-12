class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> result;
        for (const auto& item : words) {
            for (const auto& item2 : words) {
                if (item == item2) {
                    continue;
                }
                if (item2.find(item) != std::string::npos) {
                    result.emplace_back(item);
                    break;
                }
            }
        }
        return result;
    }
};