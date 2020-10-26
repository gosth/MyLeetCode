struct Node {
    char m_value;
    int m_count;

    Node(char feature, int count) : m_value(feature), m_count(count) {
    }

    bool operator<(const Node& node) const {
        return m_count < node.m_count;
    }
};

class Solution {
public:
    string frequencySort(string s) {
        std::string result;
        std::priority_queue<Node, std::vector<Node>, std::less<Node>> bigHeap;
        std::map<char, int> mapping;
        for (const auto topic : s) {
            mapping[topic] += 1;
        }
        for (const auto& item : mapping) {
            bigHeap.emplace(Node(item.first, item.second));
        }
        while (!bigHeap.empty()) {
            auto item = bigHeap.top();
            while (item.m_count) {
                result += item.m_value;
                --item.m_count;
            }
            bigHeap.pop();
        }
        return result;
    }
};