#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    void DFS(int index_of_s, int index_of_t, const std::string& s, const std::string& t, int* result) {
        if (index_of_t == t.size()) {
            (*result) += 1;
            return;
        }
        if (index_of_s == s.size()) {
            return;
        }
        for (int s_index = index_of_s; s_index < s.size(); ++s_index) {
            if (s[s_index] == t[index_of_t]) {
                DFS(s_index + 1, index_of_t + 1, s, t, result);
            }
        }
    }

    int numDistinct(string s, string t) {
        if (s.size() < t.size()) {
            return 0;
        }
        int result = 0;
        DFS(0, 0, s, t, &result);
        return result;
    }
};

int main() {
    const std::string& a = "rabbbit";
    const std::string& b = "rabbit";
    Solution s;
    cout << s.numDistinct(a,b);
    return 0;
}