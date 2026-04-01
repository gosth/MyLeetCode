#include <unordered_map>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    void BuildPreSumToIndexMapping(int presum, int index, std::map<int, int> *presum_to_index) {
        if (presum_to_index->find(presum) == presum_to_index->end()) {
            (*presum_to_index)[presum] = index;
        }
    }

    int findMaxLength(vector<int> &nums) {
        if (1 == nums.size() || nums.empty()) {
            return 0;
        }
        std::map<int, int> presum_to_index;
        int presum = 0;
        int result = 0;
        presum_to_index[0] = -1;
        for (int index = 0; index < nums.size(); ++index) {
            if (!nums[index]) {
                presum += -1;
            } else {
                presum += 1;
            }
            if (index != 0) {
                if (auto iter = presum_to_index.find(presum); iter != presum_to_index.end()) {
                    if (result < index - iter->second) {
                        result = index - iter->second;
                    }
                }
            }
            BuildPreSumToIndexMapping(presum, index, &presum_to_index);
        }
        return result;
    }
};