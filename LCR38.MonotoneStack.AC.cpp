class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if (temperatures.empty()) {
            return {};
        }
        std::vector<int> result(temperatures.size(), 0);
        std::stack<int> indexes;
        indexes.emplace(0);
        for (int i = 1; i < temperatures.size(); ++i) {
            if (temperatures[i] <= temperatures[indexes.top()]) {
                indexes.emplace(i);
            } else {
                while (!indexes.empty() && temperatures[i] > temperatures[indexes.top()]) {
                    int index = indexes.top();
                    result[index] = i - index;
                    indexes.pop();
                }
                indexes.emplace(i);
            }
        }
        return result;
    }
};