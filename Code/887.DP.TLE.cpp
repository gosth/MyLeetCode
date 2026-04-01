class Solution {
public:
	int superEggDrop(int K, int N) {
		if (K >= 101 || N >= 10001) {
			return 0;
		}
		std::vector<std::vector<int>> status(101, std::vector<int>(10001, 0));
		for (int i = 1; i <= K; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (i == 1) {
					status[i][j] = j;
				}
				if (j == 1) {
					status[i][j] = 1;
				}
			}
		}

		for (int n = 2; n <= N; ++n) {
			for (int k = 2; k <= K; ++k) {
				status[k][n] = INT_MAX;
				for (int x = 1; x <= n; ++x) {
					status[k][n] = std::min(status[k][n], std::max(status[k][n - x], status[k - 1][x - 1]) + 1);

				}

			}
		}

		return status[K][N];
	}
};