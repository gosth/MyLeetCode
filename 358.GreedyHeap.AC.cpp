class Solution {
    public:
        string rearrangeString(string s, int k) {
            if (!k) {
                return s;
            }
            std::string result;
            std::unordered_map<char, int> mapping;
            for (const auto& item : s) {
                mapping[item] += 1;
            }
            std::priority_queue<std::pair<int, char>> store;
            for (const auto& item : mapping) {
                store.emplace(std::make_pair(item.second, item.first));
            }
            if (!store.empty()) {
                int topCount = store.top().first;
                int totalItemCount = (topCount - 1) * k + 1;
                if (s.size() < totalItemCount) {
                    return "";
                }
            }
            std::vector<std::pair<int, char>> remains;
            while (!store.empty()) {
                int popCount = -1;
                remains.clear();
                for (int index = 0; index < k; ++index) {
                    if (!store.empty()) {
                        ++popCount;
                        auto topItem = store.top();
                        store.pop();
                        result += topItem.second;
                        if (topItem.first > 1) {
                            topItem.first -= 1;
                            remains.emplace_back(topItem);
                        }
                    }
                    if (popCount != index) {
                        return "";
                    }
                    if (remains.empty() && store.empty()) {
                        break;
                    }
                }
                for (const auto& item : remains) {
                    store.emplace(item);
                }
            }
            return result;
        }
    };