class Solution {
 public:
  int strToInt(string str) {
    long result = 0;
    int sign = 0;
    bool num = false;
    for (int index = 0; index < str.size(); ++index) {
      const auto& item = str[index];
      if (num) {
        if (item < '0' || item > '9') {
          break;
        } else {
          result = result * 10 + item - '0';
        }
      } else {
        if (-1 == sign || 1 == sign) {
          if (item < '0' || item > '9') {
            break;
          }
        }
        if (' ' == item) {
          continue;
        } else if ('-' == item) {
          sign = -1;
        } else if ('+' == item) {
          sign = 1;
        } else if (item >= '0' && item <= '9') {
          num = true;
          result = result * 10 + item - '0';
        } else {
          break;
        }
      }
      if (result >= std::pow(2, 31) - 1) {
        if (-1 == sign) {
          if (result * -1 < INT_MIN) {
            return INT_MIN;
          }
        } else {
          if (result > INT_MAX) {
            return INT_MAX;
          }
        }
      }
    }
    if (-1 == sign) {
      result *= -1;
    }
    return result;
  }
};