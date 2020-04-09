class Solution {
public:
    string convert(string s, int numRows) {
        std::string result;
        if (1 == numRows) {
            return s;
        }
        std::vector<std::string> rows(std::min(numRows, static_cast<int>(s.size())));
        bool down = false;  // true:向下走；false：向上走
        int currentRow = 0;
        for (int index = 0; index < s.size(); ++index) {
            rows[currentRow] += s[index];
            if (0 == currentRow || numRows - 1 == currentRow) {
                down = !down;
            }
            currentRow += down ? 1 : -1;
        }
        for (const auto& item : rows) {
            result += item;
        }
        return result;
    }
};