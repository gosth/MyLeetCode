class Solution {
 public:
  int add(int a, int b) {
    while (b != 0) {
      int no_carry = a ^ b;
      int carry = static_cast<unsigned>(a & b) << 1;
      a = no_carry;
      b = carry;
    }
    return a;
  }
};