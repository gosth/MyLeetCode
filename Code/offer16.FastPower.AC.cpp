class Solution {
 public:
  double myPow(double x, int n) {
    // 如果不用long long,n为INT_MIN时求绝对值会出错
    long long exponent = n;
    long long postive_exponent = std::abs(exponent);
    double result = 1;
    while (postive_exponent > 0) {
      if (postive_exponent % 2 == 0) {
        postive_exponent >>= 1;
        x *= x;
      } else {
        result *= x;
        postive_exponent -= 1;
      }
    }
    if (exponent < 0) {
      result = 1 / result;
    }
    return result;
  }
};