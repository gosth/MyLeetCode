class Solution {
public:
    vector <vector<int>> reconstructQueue(vector <vector<int>>& people) {
        if (people.empty()) {
            return {};
        }
        std::sort(people.begin(), people.end(),
                [](const std::vector<int>& left, const std::vector<int>& right) -> bool {
                    return left.front() > right.front() ||
                            (left.front() == right.front() && left.back() < right.back());
                });
        std::vector <std::vector<int>> result;
        for (const auto& item : people) {
            result.emplace(result.begin() + item.back(), item);
        }
        return result;
    }
};