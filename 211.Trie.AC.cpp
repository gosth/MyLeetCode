// 没有实现析构，会内存泄露
#define TRIE_MAX_CHAR_NUM 26

struct TrieNode {
    TrieNode* child[TRIE_MAX_CHAR_NUM];
    bool isEnd;

    TrieNode() : isEnd(false) {
        for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i) {
            child[i] = 0;
        }
    }
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }

    /** Inserts a word into the trie. */
    void addWord(string word) {
        TrieNode* ptr = &m_root;
        if (word.size()) {
            for (const auto& item : word) {
                int pos = item - 'a';
                if (!ptr->child[pos]) {
                    ptr->child[pos] = newNode();
                }
                ptr = ptr->child[pos];
            }
            ptr->isEnd = true;
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.size()) {
            return searchFromNode(&m_root, word);
        }
        return false;
    }

private:
    TrieNode m_root;
    std::vector<TrieNode*> m_nodeVec;

    TrieNode* newNode() {
        TrieNode* node = new TrieNode();
        //        m_nodeVec.emplace_back(node);
        return node;
    }

    bool searchFromNode(const TrieNode* node, const std::string& word) {
        if (word.empty()) {
            return node->isEnd ? true : false;
        }
        if (word.front() == '.') {
            for (int i = 0; i < TRIE_MAX_CHAR_NUM; ++i) {
                if (node->child[i] && searchFromNode(node->child[i], word.substr(1))) {
                    return true;
                }
            }
        } else {
            int pos = word.front() - 'a';
            if (node->child[pos] && searchFromNode(node->child[pos], word.substr(1))) {
                return true;
            }
        }
        return false;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */