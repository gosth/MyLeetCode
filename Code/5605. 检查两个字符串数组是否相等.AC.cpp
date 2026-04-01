class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        std::string item1, item2;
        for (const auto& item : word1) {
            item1 += item;
        }
        for (const auto& item : word2) {
            item2 += item;
        }
        return item1 == item2;
    }
};