  class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            std::sort(intervals.begin(),
                    intervals.end(),
                    [](const std::vector<int>& item1, const std::vector<int>& item2) {
                        return item1.back() < item2.back();
                    });
            const int totalSize = intervals.size();
            int useCount = 0, currentEndIndex = INT_MIN;
            for (const auto& item : intervals) {
                if (item.front() >= currentEndIndex) {
                    ++useCount;
                    currentEndIndex = item.back();
                }
            }
            return totalSize - useCount;
        }
    };