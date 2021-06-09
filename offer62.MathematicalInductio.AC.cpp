class Solution {
 public:
  int lastRemaining(int n, int m) {
    int result = 0;
    for (int index = 2; index <= n; ++index) {
      result = (result + m) % index;
    }
    return result;
  }
};