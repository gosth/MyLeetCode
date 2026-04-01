#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    void DFS(int current_index, const vector<int>& nums, std::unordered_set<int>* indexs, std::vector<int>* temp, std::vector<std::vector<int>>* results) {
        temp->emplace_back(nums[current_index]);
        indexs->emplace(current_index);
        if (temp->size() == nums.size()) {
            results->emplace_back(*temp);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (indexs->find(i) == indexs->end()) {
                DFS(i, nums, indexs, temp, results);
                temp->pop_back();
                indexs->erase(i);
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> results;
        for (int i = 0; i < nums.size(); ++i) {
            std::vector<int> temp;
            std::unordered_set<int> indexs;
            DFS(i, nums, &indexs, &temp, &results);
        }
        return results;
    }
};
