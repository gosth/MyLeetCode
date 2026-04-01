class Solution {
    void recursive(int x, int y, int m, int n, int* pathCount) {
        if (x == m || y == n) {
            return;
        }
        if (x == m - 1 && y == n - 1) {
            *pathCount += 1;
            return;
        }
        recursive(x + 1, y, m, n, pathCount);
        recursive(x, y + 1, m, n, pathCount);
    }

public:
    int uniquePaths(const int m, const int n) {
        if (m == 1 || n == 1) {
            return 1;
        }
        int x = 0, y = 0, pathCount = 0;
        recursive(x, y, m, n, &pathCount);
        return pathCount;
    }
};

int main() {
    Solution s;
    cout << s.uniquePaths(23, 12) << endl;
    getchar();
    return 0;
}