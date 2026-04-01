class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        std::map<int, int> count;
        for (auto& item : arr) {
            count[item] += 1;
        }
        priority_queue<Node, vector<Node>, greater<Node> > heap;    //小根堆
        for (auto& item : count) {
            heap.emplace(Node(item.first, item.second));
        }
        while (k || heap.empty()) {
            auto current = heap.top();
            if (current.y > k) {
                return heap.size();
            } else if (current.y == k) {
                heap.pop();
                return heap.size();
            } else {
                k -= current.y;
                heap.pop();
            }
        }
        return heap.size();
    }
};