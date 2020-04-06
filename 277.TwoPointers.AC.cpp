/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int left = 0, right = n - 1;
        while (left < right) {
            if (knows(left, right)) {
                ++left;
            } else {
                --right;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!knows(i, left)) {
                return -1;
            }
            if (i != left && knows(left, i)) {
                return -1;
            }
        }
        return left;
    }
};