class Solution {
 public:
  void AddEdge(const std::string& first_word, const std::string& second_word) {
    int min_length = std::min(first_word.size(), second_word.size());
    int word_index = 0;
    for (; word_index < min_length; word_index++) {
      if (first_word[word_index] != second_word[word_index]) {
        if (edges_[first_word[word_index]].find(second_word[word_index]) ==
            edges_[first_word[word_index]].end()) {
          edges_[first_word[word_index]].emplace(second_word[word_index]);
          in_degrees[second_word[word_index]] += 1;
          break;
        } else {
          break;
        }
      }
    }
    if (word_index == min_length && first_word.size() > second_word.size()) {
      is_valid_ = false;
    }
  }
  string alienOrder(vector<string>& words) {
    for (const auto& word : words) {
      for (const auto& item : word) {
        in_degrees[item] = 0;
      }
    }
    for (int word_index = 1; word_index < words.size() && is_valid_; word_index++) {
      AddEdge(words[word_index - 1], words[word_index]);
    }
    if (!is_valid_) {
      return "";
    }
    std::string candidate_result;
    std::deque<char> queue;
    for (const auto& [key, value] : in_degrees) {
      if (!value) {
        queue.emplace_back(key);
      }
    }
    while (!queue.empty()) {
      const auto current_word = queue.front();
      candidate_result += current_word;
      queue.pop_front();
      if (auto iter = edges_.find(current_word); iter != edges_.end()) {
        for (const auto& item : iter->second) {
          in_degrees[item] -= 1;
          if (!in_degrees[item]) {
            queue.emplace_back(item);
          }
        }
      }
    }
    return candidate_result.size() == in_degrees.size() ? candidate_result : "";
  }
  std::unordered_map<char, std::set<char>> edges_;
  std::unordered_map<char, int> in_degrees;
  bool is_valid_ = true;
};