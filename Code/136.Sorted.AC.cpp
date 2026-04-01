#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int preVal = INT_MIN;
        nums.push_back(INT_MIN);
        for (size_t i = 0; i < nums.size(); ++i) {
            if (i % 2 == 0) {
                preVal = nums[i];
            } else {
                if (preVal != nums[i]) {
                    return preVal;
                }
            }
        }
    }
};

int main() {
    vector<int> a = {4,1,2,1,2};
    Solution b;
    cout << b.singleNumber(a) << endl;
}