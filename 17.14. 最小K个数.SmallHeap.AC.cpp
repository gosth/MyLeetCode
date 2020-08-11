
    class Solution {
    public:
        vector<int> smallestK(vector<int>& arr, int k) {
            std::vector<int> result;
            std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
            if (k >= arr.size()) {
                return arr;
            }
            for (const auto& item : arr) {
                heap.emplace(item);
            }
            for (int featureIndex = 0; featureIndex < k; ++featureIndex) {
                result.emplace_back(heap.top());
                heap.pop();
            }
            return result;
        }
    };