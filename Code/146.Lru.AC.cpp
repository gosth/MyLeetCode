class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity) {

    }

    int get(int key) {
        auto iter = m_mapping.find(key);
        if (iter != m_mapping.end()) {
            m_linkedList.splice(m_linkedList.begin(), m_linkedList, iter->second);
            return m_linkedList.front().second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto iter = m_mapping.find(key);
        m_linkedList.emplace_front(std::make_pair(key, value));
        if (iter != m_mapping.end()) {
            m_linkedList.erase(iter->second);
            m_mapping.erase(iter);
        }
        m_mapping[key] = m_linkedList.begin();
        if (m_linkedList.size() > m_capacity) {
            auto last = m_linkedList.end();
            --last;
            m_mapping.erase(last->first);
            m_linkedList.pop_back();
        }
    }

    std::list<std::pair<int, int>> m_linkedList;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_mapping;
    int m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */