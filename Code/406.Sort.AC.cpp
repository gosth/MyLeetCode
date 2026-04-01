class Solution {
public:
    vector <vector<int>> reconstructQueue(vector <vector<int>>& people) {
        if (people.empty()) {
            return {};
        }
        std::map < int, std::vector < std::vector < int>>> mapping;
        std::list <std::vector<int>> sequence;
        for (const auto& item : people) {
            mapping[item.front()].emplace_back(item);
        }
        for (auto& item: mapping) {
            std::sort(item.second.begin(), item.second.end(),
                    [](const std::vector<int>& left, const std::vector<int>& right) -> bool {
                        return left < right;
                    });
        }
        for (auto reverseIter = mapping.rbegin(); reverseIter != mapping.rend(); ++reverseIter) {
            for (auto& item : reverseIter->second) {
                auto insertIter = sequence.begin();
                std::advance(insertIter, item.back());
                sequence.emplace(insertIter, item);
            }
        }
        int index = 0;
        for (const auto& item : sequence) {
            people[index] = item;
            ++index;
        }
        return people;
    }
};