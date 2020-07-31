class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int result = 0;
    result += numBottles;
    int newBottles = numBottles / numExchange;
    while (newBottles != 0) {
      std::cout << newBottles << std::endl;
      result += newBottles;
      numBottles = numBottles % numExchange + newBottles;
      newBottles = numBottles / numExchange;
    }
    return result;
  }
};