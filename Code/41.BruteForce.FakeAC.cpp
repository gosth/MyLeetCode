#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <numeric>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int compare = 1;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == compare) {
                ++compare;
                continue;
            }
        }
        return compare;
    }
};

int main() {
    vector<int> a{1};
    Solution c;
    cout << c.firstMissingPositive(a) << endl;
    return 0;
}
