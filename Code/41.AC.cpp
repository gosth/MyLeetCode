#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void swap(int& a, int& b) {
        if (a != b) {
            a ^= b;
            b ^= a;
            a ^= b;
        }
    }

    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for (size_t i = 0; i < nums.size(); ++i) {
            while (nums[i] > 0 && nums[i] <= size && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return size + 1;
    }
};

int main() {
    vector<int> a{2, 3, 2};
    vector<int> b{-1, -2, 3, 68, 0, -100, 10, 54, 8, -12};
    Solution c;
    cout << c.firstMissingPositive(a) << endl;
    cout << c.firstMissingPositive(b) << endl;
    return 0;
}