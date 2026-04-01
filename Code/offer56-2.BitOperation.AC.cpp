class Solution {
public:
    int singleNumber(vector<int> &nums) {
        std::vector<int> bits(32);
        for (auto &num : nums) {
            for (int i = 0; i < 32; ++i) {
                bits[i] += num & 1;
                num = num >> 1;
            }
        }
        for (auto &item : bits) {
            item %= 3;
        }
        int result = 0;
        int bit_offset = 0;
        for (const auto &item : bits) {
            result += (item << bit_offset);
            bit_offset += 1;
        }
        return result;
    }
};