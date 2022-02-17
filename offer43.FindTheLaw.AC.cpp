class Solution {
 public:
  int countDigitOne(int n) {
    // result为n的每一数位为1个数的和。逐次固定住当前位，通过高位和低位求得当前位为1的个数。
    long long high = n / 10, cur = n % 10, low = 0, digit = 1;
    int result = 0;
    while (high != 0 || cur != 0) {
      if (0 == cur) {
        result += high * digit;
      } else if (1 == cur) {
        result += high * digit + low + 1;
      } else {
        // cur = 2...9
        result += (high + 1) * digit;
      }
      low += cur * digit;
      cur = high % 10;
      high /= 10;
      digit *= 10;
    }
    return result;
  }
};