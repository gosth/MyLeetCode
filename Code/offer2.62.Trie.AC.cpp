class Trie {
 public:
  /** Initialize your data structure here. */
  Trie() {
    is_end_ = false;
    children_.resize(26, nullptr);
  }

  /** Inserts a word into the trie. */
  void insert(string word) {
    Trie* node = this;
    for (const auto& item : word) {
      if (node->children_[item - 'a']) {
        node = node->children_[item - 'a'];
      } else {
        node->children_[item - 'a'] = new Trie();
        node = node->children_[item - 'a'];
      }
    }
    node->is_end_ = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    Trie* node = SearchPrefix(word);
    return node ? (node->is_end_ ? true : false) : false;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    Trie* node = SearchPrefix(prefix);
    return node ? true : false;
  }

  Trie* SearchPrefix(const std::string& prefix) {
    Trie* node = this;
    for (const auto& item : prefix) {
      if (node->children_[item - 'a']) {
        node = node->children_[item - 'a'];
      } else {
        return nullptr;
      }
    }
    return node;
  }

 private:
  std::vector<Trie*> children_;
  bool is_end_;
};