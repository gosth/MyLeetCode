class Solution {
 public:

  int DFS(const std::vector<int>& cardPoints, int startIndex, int endIndex, int value, int k) {
    if (!k) {
      return value;
    }
    return std::max(
        DFS(cardPoints, startIndex + 1, endIndex, value + cardPoints[startIndex], k - 1),
        DFS(cardPoints, startIndex, endIndex - 1, value + cardPoints[endIndex], k - 1));
  }

  int maxScore(vector<int>& cardPoints, int k) {
    int result = 0;
    if (!k || cardPoints.empty()) {
      return 0;
    }
    if (k >= cardPoints.size()) {
      for (auto& item : cardPoints) {
        result += item;
      }
      return result;
    }
    return DFS(cardPoints, 0, cardPoints.size() - 1, 0, k);
  }
}; 