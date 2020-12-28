void buildResult(const vector<int>& nums,
        std::vector<int>* isUsed,
        std::vector<int>* tempResult,
        vector<vector<int>>* result) {
    if (tempResult->size() == nums.size()) {
        result->emplace_back(*tempResult);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        auto& item = nums[i];
        if ((*isUsed)[i] == true) {
            continue;
        }
        (*isUsed)[i] = true;
        tempResult->emplace_back(item);
        buildResult(nums, isUsed, tempResult, result);
        tempResult->pop_back();
        (*isUsed)[i] = false;
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return vector<vector<int>>();
        }
        vector<vector<int>> result;
        std::vector<int> tempResult;
        std::vector<int> isUsed(nums.size());
        buildResult(nums, &isUsed, &tempResult, &result);
        return result;
    }
};