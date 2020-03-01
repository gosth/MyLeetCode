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
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
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
        TrieNode* ptr = &m_root;
        if (word.size()) {
            for (const auto& item : word) {
                int pos = item - 'a';
                if (!ptr->child[pos]) {
                    return false;
                }
                ptr = ptr->child[pos];
            }
            return ptr->isEnd;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ptr = &m_root;
        if (prefix.size()) {
            for (const auto& item : prefix) {
                int pos = item - 'a';
                if (!ptr->child[pos]) {
                    return false;
                }
                ptr = ptr->child[pos];
            }
            return true;
        }
        return true;
    }

private:
    TrieNode m_root;
    std::vector<TrieNode*> m_nodeVec;
    TrieNode*  newNode() {
        TrieNode* node = new TrieNode();
//        m_nodeVec.emplace_back(node);
        return node;
    }
};