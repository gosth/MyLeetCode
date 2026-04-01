class MaxQueue {
 public:
  MaxQueue() {}

  int max_value() {
    return max_value_store_.empty() ? -1 : max_value_store_.front();
  }

  void push_back(int value) {
    data_store_.emplace_back(value);
    while (!max_value_store_.empty() && value > max_value_store_.back()) {
      max_value_store_.pop_back();
    }
    max_value_store_.emplace_back(value);
  }

  int pop_front() {
    if (data_store_.empty()) {
      return -1;
    }
    if (data_store_.front() == max_value_store_.front()) {
      max_value_store_.pop_front();
    }
    const int value = data_store_.front();
    data_store_.pop_front();
    return value;
  }

 private:
  std::deque<int> data_store_, max_value_store_;
};