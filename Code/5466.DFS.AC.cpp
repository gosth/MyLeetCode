class Solution {
public:
	// 0, 1, 2, 3上下左右
	std::vector<int> directionX = { -1, 1, 0, 0 };
	std::vector<int> directionY = { 0, 0, -1, 1 };
	int lines = 0, columns = 0;
	// [第几块拼图][进入方向]，value为出去方向，-1为不可到达
	std::vector<std::vector<int>> pipe = {
		{ -1, -1, -1, -1 },
		{ -1, -1, 2, 3 },
		{ 0, 1, -1, -1 },
		{ 2, -1, -1, 1 },
		{ 3, -1, 1, -1 },
		{ -1, 2, -1, 0 },
		{ -1, 3, 0, -1 } };

	//(x,y,当前方向,地图)
	bool DFS(const int x, const int y, const int direction, const std::vector<std::vector<int>>& grid) {

		if (x == lines - 1 && y == columns - 1) {
			return true;
		}
		const auto nextX = x + directionX[direction];
		const auto nextY = y + directionY[direction];

		if (nextX < 0 || nextY < 0 || nextX >= lines || nextY >= columns) {
			return false;
		}
		const auto nextBlock = grid[nextX][nextY];

		if (pipe[nextBlock][direction] != -1) {
			return DFS(nextX, nextY, pipe[nextBlock][direction], grid);
		}
		return false;
	}

	bool hasValidPath(vector<vector<int>>& grid) {
		int result = false;
		if (!grid.empty() && !grid.front().empty()) {
			lines = grid.size();
			columns = grid.front().size();
			const auto start = grid.front().front();
			for (int direction = 0; direction < 4; ++direction) {
				if (pipe[start][direction] != -1) {

					if (DFS(0, 0, pipe[start][direction], grid)) {
						result = true;
						break;
					}
				}
			}
		}
		return result;
	}
};