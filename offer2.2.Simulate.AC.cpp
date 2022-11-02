#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int max_size = a.size() > b.size() ? a.size() : b.size();
        // 最高位可能进位，预留一个
        max_size += 1;
        while (a.size() < max_size) {
            a = "0" + a;
        }
        while (b.size() < max_size) {
            b = "0" + b;
        }
        std::string result;
        int carry_bit = 0;
        for (int i = max_size - 1; i >= 0; --i) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry_bit;
            result = std::to_string(sum % 2) + result;
            carry_bit = sum / 2;
        }
        if (result.front() == '0') {
            result = result.substr(1);
        }
        return result;
    }
};