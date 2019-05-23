#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    // a⊕b⊕a=(a⊕a)⊕b=0⊕b=b
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    vector<int> a = {4, 1, 2, 1, 2};
    Solution b;
    cout << b.singleNumber(a) << endl;
}