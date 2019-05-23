#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>();
        }
        vector<vector<int>> vResult;
        unordered_multimap<int, int> mapper;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                int iSum = nums[i] + nums[j];
                int iThird = 0;//防止相同的序列重复计算
                for (size_t k = j + 1; k < nums.size(); ++k) {
                    if (nums[k] == 0 - iSum) {
                        ++iThird;
                        if (iThird > 1) {
                            continue;
                        }
                        vector<int> temp{nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        auto range = mapper.equal_range(temp.front());
                        if (range.first == mapper.end() && range.second == mapper.end()) {
                            mapper.insert(std::make_pair(temp[0], temp[1]));
                            vResult.push_back(temp);
                        } else {
                            bool bIsHit = false;
                            for (auto it = range.first; it != range.second; ++it) {
                                if (it->second == temp[1]) {
                                    bIsHit = true;
                                    break;
                                }
                            }
                            if (!bIsHit) {
                                mapper.insert(std::make_pair(temp[0], temp[1]));
                                vResult.push_back(temp);
                            }
                        }
                    }
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
