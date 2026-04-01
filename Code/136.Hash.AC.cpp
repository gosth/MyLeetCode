#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int num : nums) {
            if (hashSet.find(num) != hashSet.end()) {
                hashSet.erase(num);
            } else {
                hashSet.insert(num);
            }
        }
        return *hashSet.begin();
    }
};

int main() {
    vector<int> a = {4, 1, 2, 1, 2};
    Solution b;
    cout << b.singleNumber(a) << endl;
}