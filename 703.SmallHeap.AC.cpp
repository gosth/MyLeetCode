class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        count = k;
        for (const auto& item : nums) {
            store.emplace(item);
        }
    }

    int add(int val) {
        store.emplace(val);
        while (store.size() > count) {
            store.pop();
        }
        return store.top();
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> store;
    int count;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */