class MovingAverage {
 public:
  /** Initialize your data structure here. */
  MovingAverage(int size) : max_count_(size) {}
  
    
  double next(int val) {
    if (queue_.size() >= max_count_) {
      current_sum_ -= queue_.front();
      queue_.pop_front();
    }
    current_sum_ += val;
    queue_.emplace_back(val);
    return current_sum_ * 1.0 / queue_.size();
  }
  
 public:
  std::deque<int> queue_;
  int max_count_;
  int current_sum_ = 0;
};