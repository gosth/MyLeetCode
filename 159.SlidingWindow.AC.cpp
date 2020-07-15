#include <iostream>
#include<vector>
#include<unordered_map>
#include <set>
#include <deque>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//指针的移动是难点
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() < 3) {
            return s.size();
        }
        std::unordered_map<char, int> mapping;
        int left = 0, result = 0, diffrentNum = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto &item = s[i];
            diffrentNum += (!mapping.count(item)) || (mapping[item] < left);
            if (diffrentNum > 2) {
                while (mapping[s[left]] > left) {
                    ++left;
                }
                ++left;
                --diffrentNum;
            }
            mapping[item] = i;
            result = std::max(result, i - left + 1);

        }
        return result;
    }
};

int main() {
    Solution a;
    std::cout << a.lengthOfLongestSubstringTwoDistinct("abaccc") << std::endl;
}
