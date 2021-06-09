class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int push_data_index = 0;
    int pop_data_index = 0;
    while (pop_data_index < popped.size()) {
      while (data_set_.find(popped[pop_data_index]) == data_set_.end()) {
        if (push_data_index < pushed.size()) {
          data_store_.emplace(pushed[push_data_index]);
          data_set_.emplace(pushed[push_data_index]);
          ++push_data_index;
        } else {
          return false;
        }
      }
      if (data_store_.top() == popped[pop_data_index]) {
        data_store_.pop();
        data_set_.erase(popped[pop_data_index]);
        ++pop_data_index;
      } else {
        return false;
      }
    }
    return true;
  }
 private:
  std::stack<int> data_store_;
  std::set<int> data_set_;
};