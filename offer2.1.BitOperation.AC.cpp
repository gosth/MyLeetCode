#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int a, int b) {
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        if (a == 0) {
            return 0;
        }
        if (b == 1) {
            return a;
        }
        bool is_a_posive = a > 0 ? true : false;
        bool is_b_posive = b > 0 ? true : false;
        bool is_divide_posive = !(is_a_posive ^ is_b_posive);
        int64_t first = is_a_posive ? a : static_cast<int64_t>(a) * -1;
        int64_t second = is_b_posive ? b : static_cast<int64_t>(b) * -1;
        int temp_result = 0;
        int64_t subtractor = second, multiple_subtractor = 1;
        int counter = 0;
        while (first - subtractor >= 0) {
            ++counter;
            first -= subtractor;
            subtractor = (subtractor << 1);
            temp_result += multiple_subtractor;
            multiple_subtractor = multiple_subtractor << 1;
        }
        while (first - second >= 0) {
            subtractor = subtractor >> 1;
            multiple_subtractor = multiple_subtractor >> 1;
            while (first - subtractor >= 0) {
                first -= subtractor;
                temp_result += multiple_subtractor;
            }
        }
        return is_divide_posive ? temp_result : -1 * temp_result;
    }
};


int main() {
    int a = INT_MAX, b = 2;
    Solution s;
    cout << s.divide(a, b) << endl;
//    cout << (2 << 2) << endl;
    return 0;
}
