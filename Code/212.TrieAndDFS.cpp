struct TrieNode {
  string word;
  unordered_map<char, TrieNode*> children;
  TrieNode() {
    this->word = "";
  }
};

void insertTrie(TrieNode* root, const string& word) {
  for (auto c : word) {
    if (root->children.find(c) == root->children.end()) {
      root->children[c] = new TrieNode();
    }
    root = root->children[c];
  }
  root->word = word;
}

class Solution {
 public:
  std::vector<std::vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, set<string>& res) {
    char ch = board[x][y];
    if (root->children.find(ch) == root->children.end()) {
      return;
    }
    root = root->children[ch];
    if (root->word.size() > 0) {
      res.insert(root->word);
    }

    board[x][y] = '#';
    for (const auto& dir : dirs) {
      int nx = x + dir.front();
      int ny = y + dir.back();
      if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
        if (board[nx][ny] != '#') {
          dfs(board, nx, ny, root, res);
        }
      }
    }
    board[x][y] = ch;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    TrieNode* root = new TrieNode();
    set<string> res;
    vector<string> ans;

    for (auto& word : words) {
      insertTrie(root, word);
    }
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        dfs(board, i, j, root, res);
      }
    }
    for (auto& word : res) {
      ans.emplace_back(word);
    }
    return ans;
  }
};