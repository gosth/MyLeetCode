#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int64_t factor = 1;
        while (factor * factor < x) {
            factor += 1;
        }
        if (factor * factor == x) {
            return factor;
        }
        return factor - 1;
    }
};