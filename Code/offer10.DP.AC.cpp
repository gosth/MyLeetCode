class Solution {
 public:
  int fib(int n) {
    if (0 == n) {
      return 0;
    } else if (1 == n) {
      return 1;
    }
    int first_num = 0, second_num = 1;
    for (int index = 2; index <= n; ++index) {
      int sum = (first_num + second_num) % 1000000007;
      first_num = second_num;
      second_num = sum;
    }
    return second_num;
  }
};