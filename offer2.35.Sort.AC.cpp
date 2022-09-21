class Solution {
 public:
  int GetMinutes(const std::string& time_pattern) {
    return (time_pattern[0] - '0') * 10 * 60 + (time_pattern[1] - '0') * 60 +
           (time_pattern[3] - '0') * 10 + (time_pattern[4] - '0');
  }

  int findMinDifference(vector<string>& timePoints) {
    std::sort(timePoints.begin(), timePoints.end());
    int pre_minutes = GetMinutes(timePoints.front());
    int result = INT_MAX;
    for (int feature_index = 1; feature_index < timePoints.size(); ++feature_index) {
      int current_minutes = GetMinutes(timePoints[feature_index]);
      result = std::min(result, current_minutes - pre_minutes);
      pre_minutes = current_minutes;
    }
    result = std::min(result,
                      GetMinutes(timePoints.front()) + (24 * 60) - GetMinutes(timePoints.back()));
    return result;
  }
};