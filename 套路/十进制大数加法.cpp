#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

std::string Add(const std::string& origin_s1, const std::string& origin_s2) {
    std::string s1 = origin_s1, s2 = origin_s2;
    std::string result;
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    int max_len = std::max(s1.size(), s2.size());
    int carry = 0;
    for (int i = 0; i < max_len; ++i) {
        int temp = 0;
        if (i < s1.size()) {
            temp += s1[i] - '0';
        }
        if (i < s2.size()) {
            temp += s2[i] - '0';
        }
        temp += carry;
        int current = temp % 10;
        carry = temp / 10;
        result += std::to_string(current);
    }
    if (carry) {
        result += "1";
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {

    std::string s1 = "128283183";
    std::string s2 = "456901";
    cout << Add(s1, s2);

};