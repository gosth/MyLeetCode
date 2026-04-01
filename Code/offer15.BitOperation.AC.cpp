class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n) {
            result += n & 1 ? 1 : 0;
            n >>= 1;
        }
        return result;
    }
};