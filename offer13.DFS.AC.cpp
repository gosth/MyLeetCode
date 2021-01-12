class Solution {
public:
    int getSum(int num) {
        int result = 0;
        while(num) {
            result += num % 10;
            num /= 10;
        }
        return result;
    }

    void dfs(int line, int column, int m, int n, int k, std::vector<std::vector<bool>>* visited, int* result) {
        if ((*visited)[line][column]) {
            return;
        } else {
            if (getSum(line) + getSum(column) <= k) {
                (*visited)[line][column] = true;
                *result += 1;
                if (line - 1 >= 0) {
                    dfs(line - 1, column, m, n, k, visited, result);
                }
                if (line + 1 <= m - 1) {
                    dfs(line + 1, column, m, n, k, visited, result);
                }
                if (column - 1 >= 0) {
                    dfs(line, column - 1, m, n, k, visited, result);
                }
                if (column + 1 <= n - 1) {
                    dfs(line , column + 1, m, n, k, visited, result);
                }
            }
        }

    }
    int movingCount(int m, int n, int k) {
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        if (0 == k) {
            return 1;
        }
        int result = 0;
        dfs(0, 0, m, n, k, &visited, &result);
        return result;
    }
};