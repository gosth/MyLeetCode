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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if (nums.size() < 3) {
            accumulate(nums.begin(), nums.end(), 0);
        }
        int result = nums[0] + nums[1] + nums[2];
        for (size_t i = 0; i < nums.size() - 2; ++i) {
            size_t front = i + 1;
            size_t back = nums.size() - 1;
            int tempResult = nums[i] + nums[front] + nums[back];
            while (front < back) {
                while (front < back && nums[i] + nums[front] + nums[back] > target) {
                    tempResult = nums[i] + nums[front] + nums[back];
                    result = abs(tempResult - target) < abs(result - target) ? tempResult : result;
                    --back;
                }
                while (front < back && nums[i] + nums[front] + nums[back] < target) {
                    tempResult = nums[i] + nums[front] + nums[back];
                    result = abs(tempResult - target) < abs(result - target) ? tempResult : result;
                    ++front;
                }
                if (front < back && nums[i] + nums[front] + nums[back] == target) {
                    return target;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> a{-3,-2,-5,3,-4};
    Solution c;
    cout << c.threeSumClosest(a, -1) << endl;
    return 0;
}
