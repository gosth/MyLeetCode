class Solution {
public:
    bool IsInteger(const std::string &data) {
        if (data.empty() || data.find(".") != std::string::npos) {
            return false;
        }
        int start = 0;
        if (data.front() == '+' || data.front() == '-') {
            start = 1;
            // 至少一位数字
            if (1 == data.size()) {
                return false;
            }
        }
        for (int index = start; index < data.size(); ++index) {
            if (data[index] > '9' || data[index] < '0') {
                return false;
            }
        }
        return true;
    }

    bool IsFloat(const std::string &data) {
        if (data.empty() || data.find(".") == std::string::npos) {
            return false;
        }
        int start = 0;
        if (data.front() == '+' || data.front() == '-') {
            start = 1;
        }
        size_t dot_pos = data.find(".");
        int index = start;
        for (; index < dot_pos; ++index) {
            if (data[index] > '9' || data[index] < '0') {
                return false;
            }
        }
        if (start == dot_pos) {
            if (dot_pos == data.size() - 1 || (data[dot_pos + 1] > '9' || data[dot_pos + 1] < '0')) {
                return false;
            }
        }
        for (index = dot_pos + 1; index < data.size(); ++index) {
            if (data[index] > '9' || data[index] < '0') {
                return false;
            }
        }
        return true;
    }

    bool isNumber(string s) {
        if (s.empty()) {
            return false;
        }
        int start = 0, end = s.size() - 1;
        while (start < s.size() && s[start] == ' ') {
            ++start;
        }
        while (end >= 0 && s[end] == ' ') {
            --end;
        }
        if (start > end) {
            return false;
        }
        const std::string &candidate = s.substr(start, end - start + 1);
        if (candidate.find(" ") != std::string::npos) {
            return false;
        }
        size_t pos = candidate.find("e") == std::string::npos ? candidate.find("E") : candidate.find("e");
        if (pos == std::string::npos) {
            return IsInteger(candidate) || IsFloat(candidate);
        } else {
            if (pos == end) {
                return false;
            }
            // 含指数
            const std::string &exponent = candidate.substr(pos + 1);
            // pos == pos - 1 - 0 + 1
            const std::string &num = candidate.substr(0, pos);
            return IsInteger(exponent) && (IsInteger(num) || IsFloat(num));
        }
        return false;
    }
};