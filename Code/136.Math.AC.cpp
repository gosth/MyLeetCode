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
    // 2∗(a+b+c)−(a+a+b+b+c)=c
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashSet;
        for (int num : nums) {
                hashSet.insert(num);
        }
        return 2 * accumulate(hashSet.begin(), hashSet.end(), 0) - accumulate(nums.begin(), nums.end(), 0);
    }
};

int main() {
    vector<int> a = {4, 1, 2, 1, 2};
    Solution b;
    cout << b.singleNumber(a) << endl;
}