class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    if (cardPoints.empty() || !k) {
      return 0;
    }
    int result = 0;
    if (k >= cardPoints.size()) {
      for (auto& item : cardPoints) {
        result += item;
      }
      return result;
    }
    int windowLen = cardPoints.size() - k;
    int windowValNow = 0, windowValMin = 0, totalSum = 0;
    for (int i = 0; i < windowLen; ++i) {
      windowValNow += cardPoints[i];
    }
    windowValMin = windowValNow;
    totalSum += windowValNow;
    for (int i = windowLen; i < cardPoints.size(); ++i) {
      totalSum += cardPoints[i];
      windowValNow = windowValNow - cardPoints[i - windowLen] + cardPoints[i];
      windowValMin = std::min(windowValMin, windowValNow);
    }
    return totalSum - windowValMin;
  }
};