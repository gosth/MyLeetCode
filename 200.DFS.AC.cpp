// ConsoleApplication19.cpp: 定义控制台应用程序的入口点。
//

#include <iostream>
#include <vector>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid.front().empty()) {
			return 0;
		}
		int num = 0;
		// 0:未搜索过；1：搜索过
		std::vector<std::vector<char>> sign;
		size_t length = grid.front().size(), width = grid.size();
		std::vector<char> signLine(length, '0');
		for (size_t i = 0; i < width; ++i) {
			sign.emplace_back(signLine);
		}
		std::vector<std::pair<int, int>> directions = { std::make_pair(1, 0), std::make_pair(-1, 0),
			std::make_pair(0, -1), std::make_pair(0, 1) };
		int currentXPos = 0, currentYPos = 0;
		//displayMatrix(sign);
		for (const auto& line : grid) {
			currentXPos = 0;
			for (const auto& item : line) {
				if (item == '0') {
					sign[currentYPos][currentXPos] = '1';
				}
				else if (item == '1') {
					if (sign[currentYPos][currentXPos] == '0') {
						num += 1;
						signRoundIslandItem(grid, currentYPos, currentXPos, directions, &sign);
					}
				}
				currentXPos += 1;
			}
			currentYPos += 1;
		}
		return num;
	}
private:
	void signRoundIslandItem(const vector<vector<char>>& grid, int y, int x, const std::vector<std::pair<int, int>>& directions,
		std::vector<std::vector<char>>* sign) {
		size_t length = grid.front().size(), width = grid.size();
		if (x < 0 || y < 0 || x >= length || y >= width) {
			return;
		}
		if ((*sign)[y][x] == '1' || grid[y][x] == '0') {
			(*sign)[y][x] = '1';
			return;
		}
		(*sign)[y][x] = '1';
		for (const auto& direction : directions) {
			signRoundIslandItem(grid, y + direction.first, x + direction.second, directions, sign);
		}
	}

	void displayMatrix(vector<vector<char>>& matrix) {
		for (const auto& line : matrix) {
			for (const auto& item : line) {
				cout << item << " ";
			}
			cout << std::endl;
		}
		cout << std::endl;
	}
};

int main() {
	Solution a;
	vector<char> v1 = { '1', '1', '0', '0', '0' };
	vector<char> v2 = { '1', '1', '0', '0', '0' };
	vector<char> v3 = { '0', '0', '1', '0', '0' };
	vector<char> v4 = { '0', '0', '0', '1', '1' };
	vector<vector<char>> input;
	input.emplace_back(v1);
	input.emplace_back(v2);
	input.emplace_back(v3);
	input.emplace_back(v4);
	std::cout << a.numIslands(input);
	getchar();
	return 0;
}
