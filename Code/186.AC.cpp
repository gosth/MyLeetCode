class Solution {
public:
    void exchange(char* item1, char* item2) {
        const char item3 = *item1;
        *item1 = *item2;
        *item2 = item3;
    }

    void reverse(std::vector<char>& word, size_t begin, size_t end) {
        while (begin < end) {
            exchange(&word[begin], &word[end]);
            ++begin;
            --end;
        }
    }

    void reverseWords(std::vector<char>& s) {
        if (s.empty()) {
            return;
        }
        reverse(s, 0, s.size() - 1);
        size_t begin = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (' ' == s[i]) {
                reverse(s, begin, i - 1);
                begin = i + 1;
            }
        }
        reverse(s, begin, s.size() -1);
    }
};