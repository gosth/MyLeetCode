class Solution {
    void fun(int cur, int des, int remain, int* result, std::map<int, std::vector<int>>& path) {
        if (cur == des && remain == 0) {
            *result += 1;
            return;
        }
        if (remain == 0) {
            return;
        }
        if (cur == des && remain == 1) {
            return;
        }
        --remain;
        const auto& use = path[cur];
        for (const auto& nextCur : use) {
            fun(nextCur, des, remain, result, path);
        }
    }

public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        int result = 0;
        std::map<int, std::vector<int>> path;
        for (const auto& line : relation) {
            path[line.back()].emplace_back(line.front());
        }
        fun(n - 1, 0, k, &result, path);
        return result;
    }
};