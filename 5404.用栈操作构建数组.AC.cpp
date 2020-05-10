class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int i = 1;
        for (auto& item : target) {
            for (; i <= n; ++i) {
                if (item == i) {
                    result.emplace_back("Push");
                    ++i;
                    break;
                } else {
                    result.emplace_back("Push");
                    result.emplace_back("Pop");
                }
            }
        }
        return result;
    }
};