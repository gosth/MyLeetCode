#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {

    }

    int get(int key) {
        auto index_iter = data_index_.find(key);
        if (index_iter != data_index_.end()) {
            data_store_.push_front(*(index_iter->second));
            data_store_.erase(index_iter->second);
            data_index_[key] = data_store_.begin();
            return data_store_.front().second;
        }
        return -1;
    }

    void put(int key, int value) {
        auto index_iter = data_index_.find(key);
        if (index_iter != data_index_.end()) {
            index_iter->second->second = value;
            data_store_.push_front(*(index_iter->second));
            data_store_.erase(index_iter->second);
            index_iter->second = data_store_.begin();
            return;
        }
        if (data_store_.size() == capacity_) {
            data_index_.erase(data_store_.back().first);
            data_store_.pop_back();
        }
        data_store_.push_front(std::pair<int, int>(key, value));
        data_index_[key] = data_store_.begin();
    }

public:
    std::list<std::pair<int, int>> data_store_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> data_index_;
    int capacity_;

};

int main() {

    LRUCache *obj = new LRUCache(2);
    obj->put(2, 1);
    obj->put(1, 1);
    int param_1;
    cout << obj->get(2) << std::endl;
    obj->put(4, 1);
    cout << obj->get(1) << std::endl;
//     cout << "list " << obj->data_store_.size() << endl;
//     cout << "map " << obj->data_index_.size() << endl;
//     for (const auto& item : obj->data_index_) {
//         cout << "key=" << item.first <<endl;
//     }
    cout << obj->get(2) << std::endl;


}