class Solution {
public:
    int findLucky(vector<int>& arr) {
        std::map<int, int> dict;
        for (const auto& item : arr) {
            dict[item] += 1;
        }
        int result = -1;
        for (const auto& item : dict) {
            if (item.first == item.second) {
                result = result > item.first ? result :item.first;
            }
        }
        return result;
    }
};