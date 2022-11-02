#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            int bit_sum = 0;
            for (const auto& item : nums) {
                bit_sum += (item >> i) & 1;
            }
            if (bit_sum % 3 == 1) {
                result |= 1 << i;
            }
        }
        return result;
    }
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