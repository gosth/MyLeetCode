class Solution {
 public:

  int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (!k) {
      return 0;
    }
    int result = INT_MIN;
    std::vector<int> newtestPos(128 + 1, -1);
    std::vector<int> currentChar;
    int rightIndex = 0, leftIndex = 0;
    while (rightIndex < s.size()) {

      const auto& item = s[rightIndex];
      if (k == currentChar.size()) {
        bool isExist = newtestPos[item] > -1 ? true : false;

        if (isExist) {
          newtestPos[item] = rightIndex;
        } else {
          result = std::max(result, rightIndex - leftIndex);
          int minIndex = 0, minValue = INT_MAX;
          for (int i = 0; i < currentChar.size(); ++i) {
            if (minValue > newtestPos[currentChar[i]]) {
              minValue = newtestPos[currentChar[i]];
              minIndex = i;
            }
          }
          leftIndex = newtestPos[currentChar[minIndex]] + 1;
          newtestPos[currentChar[minIndex]] = -1;
          currentChar[minIndex] = item;
          newtestPos[item] = rightIndex;
        }
      } else {
        bool isExist = newtestPos[item] > -1 ? true : false;

        if (isExist) {
          newtestPos[item] = rightIndex;
        } else {
          newtestPos[item] = rightIndex;
          currentChar.emplace_back(item);
        }
      }
      ++rightIndex;
    }

    result =
        std::max(result, static_cast<int>(s.size() - leftIndex));
    return result;
  }
};