#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int need_match = 0;
        std::unordered_map<char, int> window_count_mapping, pattern_mapping;
        for (const auto &pattern : t) {
            pattern_mapping[pattern] += 1;
            ++need_match;
        }
        int right_index = 0, left_index = 0;
        int min_length = INT_MAX;
        std::string min_result;
        while (right_index < s.size()) {
            while (!need_match) {
                const int window_length = right_index - left_index + 1;
                if (min_length > window_length) {
                    min_length = window_length;
                    min_result = s.substr(left_index, window_length);
                }
                const auto &remove_data = s[left_index];
                --window_count_mapping[remove_data];
                if (auto iter = pattern_mapping.find(remove_data); iter != pattern_mapping.end()) {
                    if (window_count_mapping[remove_data] < iter->second) {
                        ++need_match;
                        ++right_index;
                    }
                }
                ++left_index;
            }
            const auto &data = s[right_index];
            ++window_count_mapping[data];
            if (auto iter = pattern_mapping.find(data); iter != pattern_mapping.end()) {
                if (window_count_mapping[data] <= iter->second) {
                    --need_match;
                    if (!need_match) {
                        continue;
                    }
                }
            }
            ++right_index;
        }
        return min_result;
    }
};