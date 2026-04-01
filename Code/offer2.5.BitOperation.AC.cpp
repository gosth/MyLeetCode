#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        if (words.empty()) {
            return 0;
        }
        std::vector<int> bit_signs(words.size(), 0);
        for (int index = 0; index < words.size(); ++index) {
            int bit_sign = 0;
            for (const auto &character: words[index]) {
                bit_sign |= 1 << (character - 'a');
            }
            bit_signs[index] = bit_sign;
        }
        int result = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (!(bit_signs[i] & bit_signs[j])) {
                    result = std::max(result, static_cast<int>(words[i].size()) * static_cast<int>(words[j].size()));
                }
            }
        }
        return result;
    }
};