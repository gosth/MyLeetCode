class Solution {
public:
    string reorganizeString(string S) {
        if (S.empty()) {
            return "";
        }
        std::map<char, int> counter;
        for (const auto& item : S) {
            counter[item] += 1;
        }
        std::priority_queue<Node, std::vector<Node>> bigHeap;
        for (const auto& item : counter) {
            bigHeap.emplace(Node(item.first, item.second));
        }
        unsigned int maxCount = bigHeap.top().m_num;
        if (S.size() % 2 && maxCount >= S.size() / 2 + 2) {
            return "";
        }
        if (0 == S.size() % 2 && maxCount >= S.size() / 2 + 1) {
            return "";
        }
        int index = 0;
        string result(S.size(), ' ');
        while (!bigHeap.empty()) {
            auto current = bigHeap.top();
            bigHeap.pop();
            char character = current.m_character;
            int num = current.m_num;
            while (num--) {
                if (index >= S.size()) {
                    index = 1;
                }
                result[index] = character;
                index += 2;
            }
        }
        return result;
    }
};