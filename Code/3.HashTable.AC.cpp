#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;
//下标x到y之间存在的数字个数为y-x+1，也等于y-(x-1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        vector<int> dict(256, -1);
        int start = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (dict[s[i]] > start) {
                start = dict[s[i]];
            }
            dict[s[i]] = i;
            result = result > i - start ? result : i - start;
        }
        return result;
    }
};

int main() {
    string input = "bbbbb";
    Solution b;
    cout << b.lengthOfLongestSubstring(input) << endl;
}