class Solution {
    std::vector<int> endStatus;

    class CompGreater {
    public:
        bool operator()(const std::vector<int>& item1, const std::vector<int>& item2) {
            return item1.front() < item2.front();
        }
    };

public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), CompGreater());
        for (const auto& item : intervals) {
            if (endStatus.empty()) {
                endStatus.emplace_back(item.back());
                continue;
            }
            bool isPutIn = false;
            for (auto& status : endStatus) {
                if (item.front() >= status) {
                    isPutIn = true;
                    status = item.back();
                    break;
                }
            }
            if (!isPutIn) {
                endStatus.emplace_back(item.back());
            }
        }
        return endStatus.size();
    }
};