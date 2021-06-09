class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int popped_index = 0;
    for (const auto& push_item : pushed) {
      data_store_.push(push_item);
      while (!data_store_.empty() && data_store_.top() == popped[popped_index]) {
        data_store_.pop();
        ++popped_index;
      }
    }
    return data_store_.empty();
  }
 private:
  std::stack<int> data_store_;
};