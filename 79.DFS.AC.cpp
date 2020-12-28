 class Solution {
    public:
        bool isMatchPatternString(
                int currentLine,
                int currentColumn,
                int lines,
                int columns,
                std::vector<std::vector<int>>* visited,
                const std::string& word,
                const std::vector<std::vector<char>>& board) {
            if (word.empty()) {
                return true;
            }
            if (currentLine - 1 >= 0) {
                if (board[currentLine - 1][currentColumn] == word.front() &&
                        !(*visited)[currentLine - 1][currentColumn]) {
                    (*visited)[currentLine - 1][currentColumn] = 1;
                    if (isMatchPatternString(currentLine - 1, currentColumn, lines, columns, visited, word.substr(1),
                            board)) {
                        return true;
                    } else {
                        (*visited)[currentLine - 1][currentColumn] = 0;
                    }
                }
            }
            if (currentLine + 1 < lines) {
                if (board[currentLine + 1][currentColumn] == word.front() &&
                        !(*visited)[currentLine + 1][currentColumn]) {
                    (*visited)[currentLine + 1][currentColumn] = 1;
                    if (isMatchPatternString(currentLine + 1, currentColumn, lines, columns, visited, word.substr(1),
                            board)) {
                        return true;
                    } else {
                        (*visited)[currentLine + 1][currentColumn] = 0;
                    }
                }
            }
            if (currentColumn - 1 >= 0) {
                if (board[currentLine][currentColumn - 1] == word.front() &&
                        !(*visited)[currentLine][currentColumn - 1]) {
                    (*visited)[currentLine][currentColumn - 1] = 1;
                    if (isMatchPatternString(currentLine, currentColumn - 1, lines, columns, visited, word.substr(1),
                            board)) {
                        return true;
                    } else {
                        (*visited)[currentLine][currentColumn - 1] = 0;
                    }
                }
            }
            if (currentColumn + 1 < columns) {
                if (board[currentLine][currentColumn + 1] == word.front() &&
                        !(*visited)[currentLine][currentColumn + 1]) {
                    (*visited)[currentLine][currentColumn + 1] = 1;
                    if (isMatchPatternString(currentLine, currentColumn + 1, lines, columns, visited, word.substr(1),
                            board)) {
                        return true;
                    } else {
                        (*visited)[currentLine][currentColumn + 1] = 0;
                    }
                }
            }
            return false;
        }

        bool exist(vector<vector<char>>& board, string word) {
            const int lines = board.size();
            const int columns = board.front().size();
            std::vector<std::vector<int>> visited(lines, std::vector<int>(columns, 0));
            for (int line = 0; line < lines; ++line) {
                for (int column = 0; column < columns; ++column) {
                    if (board[line][column] == word.front()) {
                        visited[line][column] = 1;
                        if (isMatchPatternString(line, column, lines, columns, &visited, word.substr(1), board)) {
                            return true;
                        } else {
                            visited[line][column] = 0;
                        }
                    }
                }
            }
            return false;
        }
    };