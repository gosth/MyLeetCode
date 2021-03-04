class CQueue {
 public:
  CQueue() {
    stacks_.resize(2);
  }

  void appendTail(int value) {
    stacks_[write_index].emplace(value);
  }

  int deleteHead() {
    if (stacks_[write_index].empty() && stacks_[!write_index].empty()) {
      return -1;
    }
    auto& current_stack = stacks_[!write_index];
    if (current_stack.empty()) {
      auto& write_stack = stacks_[write_index];
      while (!write_stack.empty()) {
        current_stack.emplace(write_stack.top());
        write_stack.pop();
      }
    }
    int result = current_stack.top();
    current_stack.pop();
    return result;
  }

 private:
  std::vector<std::stack<int>> stacks_;
  int write_index = 0;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */