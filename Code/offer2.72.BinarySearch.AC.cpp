#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x, result = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (static_cast<int64_t>(mid) * mid <= x) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};