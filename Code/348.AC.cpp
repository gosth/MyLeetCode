class TicTacToe {
public:
	/** Initialize your data structure here. */
	TicTacToe(int n) : m_row1(n , 0), m_row2(n, 0), m_column1(n, 0), m_column2(n, 0), m_mainDiagonal1(0),
		m_mainDiagonal2(0), m_counterDiagonal1(0), m_counterDiagonal2(0), m_scale(n){

	}

	/** Player {player} makes a move at ({row}, {col}).
	@param row The row of the board.
	@param col The column of the board.
	@param player The player, can be either 1 or 2.
	@return The current winning condition, can be either:
	0: No one wins.
	1: Player 1 wins.
	2: Player 2 wins. */
	int move(int row, int col, int player) {
		auto& rowState = player == 1 ? m_row1 : m_row2;
		auto& columnState = player == 1 ? m_column1 : m_column2;
		auto& mainDiagonalState = player == 1 ? m_mainDiagonal1 : m_mainDiagonal2;
		auto& counterDiagonalState = player == 1 ? m_counterDiagonal1 : m_counterDiagonal2;
		rowState[row] += 1;
		columnState[col] += 1;
		if (row == col) {
			++mainDiagonalState;
		}
		if (row + col == m_scale - 1) {
			++counterDiagonalState;
		}
		return (rowState[row] == m_scale || columnState[col] == m_scale || mainDiagonalState == m_scale || counterDiagonalState == m_scale) ? player : 0;
	}
private:
	std::vector<int> m_row1;  // 玩家1各行情况
	std::vector<int> m_row2;  // 玩家2各行情况
	std::vector<int> m_column1;  // 玩家1各列情况
	std::vector<int> m_column2;  // 玩家2各列情况
	int m_mainDiagonal1;  // 玩家1主对角线和
	int m_mainDiagonal2;  // 玩家2主对角线和
	int m_counterDiagonal1;   // 玩家1副对角线和
	int m_counterDiagonal2;   // 玩家2副对角线和
	int m_scale;  // 规模，为n

};