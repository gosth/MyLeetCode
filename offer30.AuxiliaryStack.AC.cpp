class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        data_store_.emplace_back(x);
        if (index_store_.empty()) {
            index_store_.emplace(0);
        } else {
            if (x < data_store_[index_store_.top()]) {
                const int current_index = data_store_.size() - 1;
                index_store_.emplace(current_index);
            }
        }
    }

    void pop() {
        if (!data_store_.empty()) {
            if (index_store_.top() == data_store_.size() - 1) {
                index_store_.pop();
            }
            data_store_.pop_back();
        }
    }

    int top() {
        return data_store_.empty() ? 0 : data_store_.back();
    }

    int min() {
        return index_store_.empty() ? 0 : data_store_[index_store_.top()];
    }

private:
    std::stack<int> index_store_;
    std::vector<int> data_store_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */