class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        if (s.empty()) {
            return 0;
        }
        if (s.size() == 1) {
            switch(s.front()) {
                case 'I':return 1;
                case 'V':return 5;
                case 'X':return 10;
                case 'L':return 50;
                case 'C':return 100;
                case 'D':return 500;
                case 'M':return 1000;
            }
        }
        size_t i = 0;
        for (; i < s.size(); ++i) {
            string cur;
            if (i != s.size() - 1) {
                cur = s.substr(i, 2);
            }
            if (cur == "IV") {
                result += 4;
                ++i;
            } else if (cur == "IX") {
                result += 9;
                ++i;
            } else if (cur == "XL") {
                result += 40;
                ++i;
            } else if (cur == "XC") {
                result += 90;
                ++i;
            } else if (cur == "CD") {
                result += 400;
                ++i;
            } else if (cur == "CM") {
                result += 900;
                ++i;
            } else {
                switch(s[i]) {
                   case 'I': result +=1;break;
                   case 'V': result +=5;break;
                   case 'X': result +=10;break;
                   case 'L': result +=50;break;
                   case 'C': result +=100;break;
                   case 'D': result +=500;break;
                   case 'M': result +=1000;break;
                }
            }
        }
        return result;      
    }
};