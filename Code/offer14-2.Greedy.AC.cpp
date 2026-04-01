class Solution {
 public:
  int cuttingRope(int n) {
    if (2 == n) {
      return 1;
    }
    if (3 == n) {
      return 2;
    }
    int mod = 1e9 + 7;
    long result = 1;
    while (n > 4) {
      result *= 3;
      result %= mod;
      n -= 3;
    }
    return result * n % mod;
  }
};