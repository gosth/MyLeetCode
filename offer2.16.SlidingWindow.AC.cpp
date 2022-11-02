#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty() || s.size() == 1) {
            return s.size();
        }
        int result = 1;
        int window_start_index = 0;
        std::map<char, int> char_2_positon;
        char_2_positon[s.front()] = 0;
        for (int index = 1; index < s.size();
             ++index) {
            if (char_2_positon.find(s[index]) != char_2_positon.end() &&
                char_2_positon[s[index]] >= window_start_index) {
                // index - window_start_index = index - 1 - window_start_index + 1
                result = std::max(result, index - window_start_index);
                window_start_index = char_2_positon[s[index]] + 1;
            }
            char_2_positon[s[index]] = index;
        }
        result = std::max(result, static_cast<int>(s.size()) - window_start_index);
        return result;
    }
};