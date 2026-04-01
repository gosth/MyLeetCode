#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    void DFS(const std::vector<int> &nums, int index, std::vector<std::vector<int>> *results,
             std::vector<int> *candidate) {
        if (index == nums.size()) {
            results->emplace_back(*candidate);
            return;
        }
        DFS(nums, index + 1, results, candidate);
        candidate->emplace_back(nums[index]);
        DFS(nums, index + 1, results, candidate);
        candidate->pop_back();
    }

    std::vector<std::vector<int>> subsets(const std::vector<int> &nums) {
        std::vector<std::vector<int>> results;
        std::vector<int> candidate;
        DFS(nums, 0, &results, &candidate);
        return results;
    }
};