class Solution {
 public:
  int EatCostTime(int consume_speed, const std::vector<int>& piles) {
    int cost_time = 0;
    for (const auto& pile : piles) {
      cost_time += pile / consume_speed;
      cost_time += pile % consume_speed == 0 ? 0 : 1;
    }
    return cost_time;
  }

  int minEatingSpeed(vector<int>& piles, int h) {
    auto max_pile = std::max_element(piles.begin(), piles.end());
    int left = 1, right = *max_pile;
    while (left < right) {
      int mid = left + (right - left) / 2;
      int actual_cost_time = EatCostTime(mid, piles);
      if (actual_cost_time > h) {
        left = mid + 1;
      } else {
        // actual_cost_time <= h
        right = mid;
      }
    }
    return left;
  }
};