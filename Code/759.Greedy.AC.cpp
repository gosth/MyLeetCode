class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        if (schedule.empty()) {
            return std::vector<Interval>();
        }
        vector<Interval> allActivity, mergedActivity;
        for (const auto& member : schedule) {
            for (const auto& item : member) {
                allActivity.emplace_back(item);
            }
        }
        if (allActivity.empty()) {
            return std::vector<Interval>();
        }
        std::sort(allActivity.begin(),
                allActivity.end(),
                [](const Interval& item1, const Interval& item2) {
                    return item1.start < item2.start;
                });
        int startIndex = allActivity.front().start;
        int endIndex = allActivity.front().end;
        for (const auto& activity : allActivity) {
            if (activity.start <= endIndex) {
                endIndex = endIndex > activity.end ? endIndex : activity.end;
            } else {
                mergedActivity.emplace_back(Interval(startIndex, endIndex));
                startIndex = activity.start;
                endIndex = activity.end;
            }
        }
        mergedActivity.emplace_back(Interval(startIndex, endIndex));
        int startIndex2 = 0, endIndex2 = mergedActivity.front().end;
        vector<Interval> result;
        for (const auto& item : mergedActivity) {
            if (item.start - endIndex2 > 0) {
                startIndex2 = endIndex2;
                endIndex2 = item.start;
                result.emplace_back(Interval(startIndex2, endIndex2));
                endIndex2 = item.end;
            }
        }
        return result;
    }
};