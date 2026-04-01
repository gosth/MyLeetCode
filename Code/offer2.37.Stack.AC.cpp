class Solution {
 public:
  bool IsSameSignBit(int a, int b) {
    return a * b > 0;
  }

  vector<int> asteroidCollision(vector<int>& asteroids) {
    std::vector<int> stack;
    stack.emplace_back(asteroids.front());
    for (int index = 1; index < asteroids.size(); ++index) {
      if (!stack.empty()) {
        bool should_insert = false;
        while (!stack.empty()) {
          auto top = stack.back();
          if (IsSameSignBit(top, asteroids[index])) {
            stack.emplace_back(asteroids[index]);
            break;
          } else {
            if (top < 0) {
              stack.emplace_back(asteroids[index]);
              break;
            } else {
              if (std::abs(top) == std::abs(asteroids[index])) {
                stack.pop_back();
                break;
              } else if (std::abs(top) > std::abs(asteroids[index])) {
                break;
              } else {
                stack.pop_back();
                if (stack.empty()) {
                  should_insert = true;
                }
              }
            }
          }
        }
        if (should_insert) {
          stack.emplace_back(asteroids[index]);
        }
      } else {
        stack.emplace_back(asteroids[index]);
      }
    }
    return stack;
  }
};