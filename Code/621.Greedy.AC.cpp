class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            std::unordered_map<int, int> counter;
            for (const auto& item : tasks) {
                counter[item] += 1;
            }
            std::priority_queue<int> store;
            for (const auto& item : counter) {
                store.emplace(item.second);
            }
            std::vector<int> remains;
            int result = 0;
            while (!store.empty()) {
                int i = 0;
                remains.clear();
                while (i <= n) {
                    if (!store.empty()) {
                        int top = store.top();
                        store.pop();
                        if (top > 1) {
                            --top;
                            remains.emplace_back(top);
                        }
                    }
                    ++result;
                    if (store.empty() && remains.empty()) {
                        break;
                    }
                    ++i;
                }
                for (const auto& item : remains) {
                    store.emplace(item);
                }
            }
            return result;
        }
    };