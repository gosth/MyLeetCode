#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& num) {
        vector<vector<int>> result;
        if (num.size() < 3) {
            return result;
        }
        sort(num.begin(), num.end());
        for (size_t i = 0; i < num.size(); ++i) {
            const int target = 0 - num[i];
            size_t front = i + 1;
            size_t back = num.size() - 1;
            while (front < back) {
                while (front < back && num[front] + num[back] < target) {
                    ++front;
                }
                while (front < back && num[front] + num[back] > target) {
                    --back;
                }
                if (front < back && num[front] + num[back] == target) {
                    vector<int> temp{num[i], num[front], num[back]};
                    result.push_back(temp);
                    while(front < back && num[front] == temp[1]) {
                        ++front;
                    }
                    while(front < back && num[back] == temp[2]) {
                        --back;
                    }
                }
            }
            while (i + 1 < num.size() && num[i+1] == num[i]) {
                ++i;
            }
        }
        return result;
    }
};

int main() {
    vector<int> a{1, 1, 3};
    Solution c;
    c.threeSum(a);
    return 0;
}
