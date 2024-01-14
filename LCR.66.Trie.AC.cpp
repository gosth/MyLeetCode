struct TrieNode {
 public:
  TrieNode() : elements_(26, nullptr) {}
  void Insert(const std::string& key, int value) {
    TrieNode* current_node = this;
    for (int i = 0; i < key.size(); ++i) {
      if (current_node->elements_[key[i] - 'a'] == nullptr) {
        current_node->elements_[key[i] - 'a'] = new TrieNode();
      }
      current_node = current_node->elements_[key[i] - 'a'];
    }
    current_node->value_ = value;
  }

  int Sum(const std::string& key) {
    if (key.empty()) {
      return 0;
    }
    TrieNode* current_node = this;
    for (const auto& item : key) {
      if (current_node->elements_[item - 'a']) {
        current_node = current_node->elements_[item - 'a'];
      } else {
        return 0;
      }
    }
    return SumProcess(current_node);
  }

  int SumProcess(TrieNode* node) {
    if (!node) {
      return 0;
    }
    int result = node->value_;
    for (const auto& element : node->elements_) {
      result += SumProcess(element);
    }
    return result;
  }

 private:
  std::vector<TrieNode*> elements_;
  bool is_finished = false;
  int value_ = 0;
};

class MapSum {
 public:
  /** Initialize your data structure here. */
  MapSum() {
    trie_node_ = new TrieNode();
  }

  void insert(string key, int val) {
    trie_node_->Insert(key, val);
  }

  int sum(string prefix) {
    return trie_node_->Sum(prefix);
  }

 private:
  TrieNode* trie_node_;
};