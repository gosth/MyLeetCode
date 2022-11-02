class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (data_mapping_.find(val) != data_mapping_.end()) {
            return false;
        }
        data_array_.emplace_back(val);
        data_mapping_[val] = data_array_.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto iter = data_mapping_.find(val);
        if (iter == data_mapping_.end()) {
            return false;
        }
        int delete_index = iter->second;
        data_mapping_.erase(val);
        if (data_array_.size() == 1 || delete_index == data_array_.size() - 1) {
            data_array_.pop_back();
            return true;
        }
        data_array_[delete_index] = data_array_.back();
        data_array_.pop_back();
        data_mapping_[data_array_[delete_index]] = delete_index;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data_array_[rand() % data_array_.size()];
    }
private:
    std::vector<int> data_array_;
    std::unordered_map<int, int> data_mapping_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */