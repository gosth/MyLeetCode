bool cmp(const std::vector<int>& item1, const std::vector<int>& item2) {
        return item1.back() < item2.back();
    }

    class Solution {
    public:
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
            std::sort(people.begin(), people.end(), cmp);
            std::map<int, std::vector<std::vector<int>>> counter;
            for (const auto& item : people) {
                counter[item.front()].emplace_back(item);
            }
            for (auto it = counter.rbegin(); it != counter.rend(); ++it) {
                for (const auto& item : it->second) {
                    auto pos = std::begin(m_dataList);
                    std::advance(pos, item.back());
                    m_dataList.emplace(pos, item);
                }
            }
            std::vector<vector<int>> result;
            for (const auto& data : m_dataList) {
                result.emplace_back(data);
            }
            return result;
        }

        std::list<std::vector<int>> m_dataList;
    };