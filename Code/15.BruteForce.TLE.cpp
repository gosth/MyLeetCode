#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    //两个vector求交集
    vector<int> vectors_intersection(vector<int>& v1, vector<int>& v2) {
        vector<int> v;
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v));//求交集
        return v;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>();
        }
        vector<vector<int>> vResult;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                int iSum = nums[i] + nums[j];
                for (size_t k = j + 1; k < nums.size(); ++k) {
                    const int val = nums[k];
                    if (val == 0 - iSum) {
                        vector<int> temp{nums[i], nums[j], nums[k]};
                        vResult.push_back(temp);
                    }
                }
            }
        }
        for (vector<vector<int>>::iterator i = vResult.begin();
             i != vResult.end();
             ++i) {
             for (vector<vector<int>>::iterator j = i + 1;
                  j != vResult.end();
                  ++j) {
                  vector<int> vInter = vectors_intersection(*i, *j);
                  if (vInter.size() == 3) {
                      j = vResult.erase(j);
                      --j;
                  }
             }
        }
        return vResult;
    }
};

int main() {
    vector<int> a{1, 1, 3};
    Solution c;
    c.threeSum(a);
    return 0;
}
