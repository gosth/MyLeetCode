class Solution {
        public:
            int nthUglyNumber(int n) {
                std::priority_queue<long long, std::vector<long long>, std::greater<long long>> store;
                store.emplace(1);
                std::set<long long> records;
                records.emplace(1);
                std::vector<int> divisors{ 2, 3, 5 };
                int currentCount = 0;
                long long currentValue = 0;
                while (currentCount != n) {
                    currentValue = store.top();
                    for (const auto item : divisors) {
                        long long newNum = currentValue * item;
                        if (records.find(newNum) != records.end()) {
                            continue;
                        } else {
                            records.emplace(newNum);
                            store.emplace(newNum);
                        }
                    }
                    store.pop();
                    ++currentCount;
                }
                return currentValue;
            }
        };