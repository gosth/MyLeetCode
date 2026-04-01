class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>* board) {
        if (i < 0 || i >= board->size() || j < 0 || j >= board->front().size() || (*board)[i][j] == 'X' ||
                (*board)[i][j] == '#') {
            return;
        }
        (*board)[i][j] = '#';
        DFS(i - 1, j, board);
        DFS(i + 1, j, board);
        DFS(i, j - 1, board);
        DFS(i, j + 1, board);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty() || board.front().empty()) {
            return;
        }
        int length = board.front().size();
        int width = board.size();

        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < length; ++j) {
                if ((i == 0 || j == 0 || i == width - 1 || j == length - 1) && board[i][j] == 'O') {
                    DFS(i, j, &board);
                }
            }
        }



        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < length; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < length; ++j) {
                if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};