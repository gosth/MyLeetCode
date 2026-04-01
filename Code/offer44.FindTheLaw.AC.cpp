class Solution {
 public:
  int findNthDigit(int n) {
    if (n == 0) {
      return 0;
    }
    // 数位，当前数位数字个数，当前数位总位数
    long digit = 1, num_count = 9, digit_count = 9;
    while (n > digit_count) {
      n -= digit_count;
      digit += 1;
      num_count *= 10;
      digit_count = digit * num_count;
    }
    // 目标所在的数
    int num = std::pow(10, digit - 1) + (n - 1) / digit;
    return std::to_string(num)[(n - 1) % digit] - '0';
  }
};