#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:

    void DFS(int num, int n, int k, std::vector<std::vector<int>> *results, std::vector<int> *temp) {
        temp->emplace_back(num);
        if (temp->size() == k) {
            results->emplace_back(*temp);
            return;
        }
        for (int i = num + 1; i <= n; ++i) {
            DFS(i, n, k, results, temp);
            temp->pop_back();
        }
    }

    void FillData(int n, int k, std::vector<std::vector<int>> *results) {
        for (int i = 1; i <= n - k + 1; ++i) {
            std::vector<int> temp;
            DFS(i, n, k, results, &temp);
        }

    }

    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> results;
        FillData(n, k, &results);
        return results;
    }
};
