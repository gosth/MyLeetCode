 class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if (intervals.size() < 2) {
                return intervals;
            }
            std::sort(intervals.begin(), intervals.end(),
                    [](const std::vector<int>& item1, const std::vector<int>& item2) {
                        return item1.front() < item2.front();
                    });
            int startPos = intervals.front().front();
            int endPos = intervals.front().back();
            std::vector<std::vector<int>> result;
            for (const auto& item : intervals) {
                if (item.front() <= endPos) {
                    if (item.back() > endPos) {
                        endPos = item.back();
                    }
                } else {
                    result.emplace_back(std::vector<int>{ startPos, endPos });
                    startPos = item.front();
                    endPos = item.back();
                }
            }
            result.emplace_back(std::vector<int>{ startPos, endPos });
            return result;
        }
    };