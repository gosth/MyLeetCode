class Solution {
public:
    string replaceSpace(string s) {
        std::size_t pos = 0;
        while (1) {
            pos = s.find(" ", pos);
            if (pos != std::string::npos) {
                s.replace(pos, 1/*空格的长度*/, "%20");
                pos += 1;
            } else {
                break;
            }
        }
        return s;
    }
};