#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        set<int> orderedNums;
        for (int num : nums) {
            orderedNums.insert(num);
        }
        for (int num : orderedNums) {
            if (!orderedNums.count(num - 1)) {  // 没有前一节点，避免重复计算
                int tempResult = 1;
                int i = 1;
                while (orderedNums.count(num + i)) {
                    ++tempResult;
                    ++i;
                }
                result = result > tempResult ? result : tempResult;
            }
        }
        return result;
    }
};

int main() {
    vector<int> a = {1, 2, 3};
    Solution b;
    cout << b.longestConsecutive(a) << endl;
}