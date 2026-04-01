
    class Solution {
    public:
        bool verifyPreorder(vector<int>& preorder) {
            int lowerBound = INT_MIN;
            std::stack<int> stackStore;
            for (const auto& item : preorder) {
                if (item < lowerBound) {
                    return false;
                }
                while (!stackStore.empty() && item > stackStore.top()) {
                    lowerBound = stackStore.top();
                    stackStore.pop();
                }
                stackStore.emplace(item);
            }
            return true;
        }
    };